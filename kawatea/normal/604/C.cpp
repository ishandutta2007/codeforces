#include <cstdio>
#include <algorithm>

using namespace std;

char s[100001];
int a[100000];
int dp[100001][3][2];

int main()
{
    int n, ans = 0, i, j, k;
    
    scanf("%d", &n);
    scanf("%s", s);
    
    for (i = 0; i < n; i++) a[i] = s[i] - '0';
    
    dp[0][0][a[0]] = dp[0][1][1 - a[0]] = 1;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 2; k++) {
                if (j == 0 || j == 2) {
                    if (a[i + 1] == k) {
                        dp[i + 1][j][a[i + 1]] = max(dp[i + 1][j][a[i + 1]], dp[i][j][k]);
                        if (j == 0) dp[i + 1][j + 1][1 - a[i + 1]] = max(dp[i + 1][j + 1][1 - a[i + 1]], dp[i][j][k] + 1);
                    } else {
                        dp[i + 1][j][a[i + 1]] = max(dp[i + 1][j][a[i + 1]], dp[i][j][k] + 1);
                        if (j == 0) dp[i + 1][j + 1][1 - a[i + 1]] = max(dp[i + 1][j + 1][1 - a[i + 1]], dp[i][j][k]);
                    }
                } else {
                    if (a[i + 1] == k) {
                        dp[i + 1][j][1 - a[i + 1]] = max(dp[i + 1][j][1 - a[i + 1]], dp[i][j][k] + 1);
                        dp[i + 1][j + 1][a[i + 1]] = max(dp[i + 1][j + 1][a[i + 1]], dp[i][j][k]);
                    } else {
                        dp[i + 1][j][1 - a[i + 1]] = max(dp[i + 1][j][1 - a[i + 1]], dp[i][j][k]);
                        dp[i + 1][j + 1][a[i + 1]] = max(dp[i + 1][j + 1][a[i + 1]], dp[i][j][k] + 1);
                    }
                }
            }
        }
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            ans = max(ans, dp[n - 1][i][j]);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}