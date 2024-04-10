#include <stdio.h>

long long dp[3001][100][2];

int main()
{
    int n, l, m = 1000000007, i, j, k, p;
    long long sum = 0;
    int a[100][2];
    
    scanf("%d %d", &n, &l);
    
    for (i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    
    for (i = 0; i <= l; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        if (a[i][0] <= l) dp[a[i][0]][i][0] = 1;
        
        if (a[i][0] != a[i][1] && a[i][1] <= l) dp[a[i][1]][i][1] = 1;
    }
    
    for (i = 0; i < l; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < 2; k++) {
                if (dp[i][j][k] == -1) continue;
                
                for (p = 0; p < n; p++) {
                    if (p == j) continue;
                    
                    if (a[p][0] == a[j][k] && i + a[p][1] <= l) {
                        if (dp[i + a[p][1]][p][1] == -1) dp[i + a[p][1]][p][1] = 0;
                        
                        dp[i + a[p][1]][p][1] += dp[i][j][k];
                        dp[i + a[p][1]][p][1] %= m;
                    }
                    
                    if (a[p][0] != a[p][1] && a[p][1] == a[j][k] && i + a[p][0] <= l) {
                        if (dp[i + a[p][0]][p][0] == -1) dp[i + a[p][0]][p][0] = 0;
                        
                        dp[i + a[p][0]][p][0] += dp[i][j][k];
                        dp[i + a[p][0]][p][0] %= m;
                    }
                }
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2; j++) {
            if (dp[l][i][j] == -1) continue;
            
            sum += dp[l][i][j];
            sum %= m;
        }
    }
    
    printf("%d\n", (int)sum);
    
    return 0;
}