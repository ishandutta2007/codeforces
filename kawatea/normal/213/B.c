#include <stdio.h>

long long c[101][101];
long long dp[11][101];

int main()
{
    int n, m = 1000000007, p = 0, i, j, k, l, r;
    long long sum = 0;
    int a[10];
    
    scanf("%d", &n);
    
    for (i = 0; i < 10; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < 10; i++) p += a[i];
    
    if (p == 0) p = 1;
    
    c[0][0] = 1;
    
    for (i = 1; i <= 100; i++) {
        c[i][0] = c[i][i] = 1;
        
        for (j = 1; j < i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % m;
    }
    
    for (i = p; i <= n; i++) {
        for (j = 1; j <= 9; j++) {
            for (k = 0; k <= 10; k++) {
                for (l = 0; l <= n; l++) {
                    dp[k][l] = -1;
                }
            }
            
            dp[0][1] = 1;
            
            for (k = 0; k < 10; k++) {
                for (l = 1; l <= i; l++) {
                    if (dp[k][l] == -1) continue;
                    
                    for (r = a[k] - (j == k); l + r <= i; r++) {
                        if (r < 0) continue;
                        
                        if (dp[k + 1][l + r] == -1) dp[k + 1][l + r] = 0;
                        
                        dp[k + 1][l + r] = (dp[k + 1][l + r] + dp[k][l] * c[i - l][r] % m) % m;
                    }
                }
            }
            
            if (dp[10][i] >= 0) sum = (sum + dp[10][i]) % m;
        }
    }
    
    printf("%d\n", (int)sum);
    
    return 0;
}