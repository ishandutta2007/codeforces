#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f3f3f3f
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

__int64 dp[45][3][3];
int n;

__int64 solve() {
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                dp[i][j][k] = min(dp[i][j][k], min(dp[i - 1][j][3 - j - k], dp[i - 1][j][k] + dp[i - 1][k][3 - j - k]) + dp[1][j][k] + min(dp[i - 1][3 - j - k][k], dp[i - 1][3 - j - k][j] + dp[i - 1][j][k]));
                dp[i][j][k] = min(dp[i][j][k], min(dp[i - 1][j][k], dp[i - 1][j][3 - j - k] + dp[i - 1][3 - j - k][k]) + dp[1][j][3 - j - k] + min(dp[i - 1][k][j], dp[i - 1][k][3 - j - k] + dp[i - 1][3 - j - k][j]) + dp[1][3 - j - k][k] + min(dp[i - 1][j][k], dp[i - 1][j][3 - j - k] + dp[i - 1][3 - j - k][k]));
            }
        }
    }
    if (n == 1) dp[n][0][2] = min(dp[n][0][2], dp[n][0][1] + dp[n][1][2]);
    return dp[n][0][2];
}

int main() {
    int i, j, k;
    for (i = 0; i <= 40; i++)
        for (j = 0; j < 3; j++)
            for (k = 0; k < 3; k++) {
                dp[i][j][k] = INF;
            }
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%I64d", &dp[1][i][j]);
    scanf("%d", &n);    
    printf("%I64d\n", solve());
    return 0;
}