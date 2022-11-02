#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000][1000];
int dp[4][1001][1001];

int main()
{
    int n, m, ans = 0, i, j;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            int x = 0;
            
            if (i > 0) x = max(x, dp[0][i - 1][j]);
            if (j > 0) x = max(x, dp[0][i][j - 1]);
            
            dp[0][i][j] = x + a[i][j];
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = m - 1; j >= 0; j--) {
            int x = 0;
            
            if (i > 0) x = max(x, dp[1][i - 1][j]);
            if (j < m - 1) x = max(x, dp[1][i][j + 1]);
            
            dp[1][i][j] = x + a[i][j];
        }
    }
    
    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < m; j++) {
            int x = 0;
            
            if (i < n - 1) x = max(x, dp[2][i + 1][j]);
            if (j > 0) x = max(x, dp[2][i][j - 1]);
            
            dp[2][i][j] = x + a[i][j];
        }
    }
    
    for (i = n - 1; i >= 0; i--) {
        for (j = m - 1; j >= 0; j--) {
            int x = 0;
            
            if (i < n - 1) x = max(x, dp[3][i + 1][j]);
            if (j < m - 1) x = max(x, dp[3][i][j + 1]);
            
            dp[3][i][j] = x + a[i][j];
        }
    }
    
    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < m - 1; j++) {
            ans = max(ans, dp[0][i - 1][j] + dp[1][i][j + 1] + dp[2][i][j - 1] + dp[3][i + 1][j]);
            ans = max(ans, dp[0][i][j - 1] + dp[1][i - 1][j] + dp[2][i + 1][j] + dp[3][i][j + 1]);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}