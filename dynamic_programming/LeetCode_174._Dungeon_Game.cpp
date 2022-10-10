class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();

        //set the size of dp bigger thatn dungeon (to avoid error when I need d[[i+1][j] or dp[i][j+1])
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN));

        //initialize the dp[m - 1][n - 1] which is the last value of dungeon
        //we have to initialize it because this value is the unique value which you don't need to "take" from other
        //we just have to take the value that is in dungeon  
        dp[m - 1][n - 1] = dungeon[m - 1][n - 1];
        if (dp[m - 1][n - 1] > 0)dp[m - 1][n - 1] = 0;

        //start to fill the dp
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)continue;
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]) + dungeon[i][j];
                if (dp[i][j] > 0)dp[i][j] = 0;
            }
        }

        //since in dp we saved how many health we spent to arrive to the end point in negative we have to change it in positive
        //to make sure that we don't die we need at least 1 health, so health that we have to spent + 1
        return (dp[0][0] * -1) + 1;
    }
};
