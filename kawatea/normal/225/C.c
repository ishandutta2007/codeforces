#include <stdio.h>

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

char s[1000][1001];
int dp[1001][1001][2];

int main()
{
    int n, m, x, y, ans = 1e9, i, j, k;
    int a[1000] = {0};
    
    scanf("%d %d %d %d", &n, &m, &x, &y);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == '#') a[j]++;
        }
    }
    
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= m; j++) {
            for (k = 0; k < 2; k++) {
                dp[i][j][k] = 1e9;
            }
        }
    }
    
    dp[0][0][0] = dp[0][0][1] = 0;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < 2; k++) {
                int p, q;
                
                if (dp[i][j][k] == 1e9) continue;
                
                if (k == 0) {
                    p = a[i];
                    q = n - a[i];
                } else {
                    p = n - a[i];
                    q = a[i];
                }
                
                if (j + 1 <= y) dp[i + 1][j + 1][k] = min(dp[i + 1][j + 1][k], dp[i][j][k] + p);
                
                if (j >= x) dp[i + 1][1][(k + 1) % 2] = min(dp[i + 1][1][(k + 1) % 2], dp[i][j][k] + q);
            }
        }
    }
    
    for (i = x; i <= y && i <= m; i++) {
        for (j = 0; j < 2; j++) {
            ans = min(ans, dp[m][i][j]);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}