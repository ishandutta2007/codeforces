#include <stdio.h>

int max(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int n, m, K, ans = 0, i, j, k, l, p;
    int a[10][100], b[10][100], c[10][100];
    
    scanf("%d %d %d", &n, &m, &K);
    
    for (i = 0; i < n; i++) {
        char s[11];
        
        scanf("%s", s);
        
        for (j = 0; j < m; j++) scanf("%d %d %d", &a[i][j], &b[i][j], &c[i][j]);
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int dp[101][101] = {0};
            
            if (i == j) continue;
            
            for (k = 0; k < m; k++) {
                for (l = 0; l <= K; l++) {
                    for (p = 0; p <= c[i][k] && l + p <= K; p++) {
                        dp[k + 1][l + p] = max(dp[k + 1][l + p], dp[k][l] + p * (b[j][k] - a[i][k]));
                    }
                }
            }
            
            for (k = 1; k <= K; k++) ans = max(ans, dp[m][k]);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}