#include <stdio.h>

int dp[11][2][11];
long long dp2[7][11][11];
long long comb[7][7];

int main()
{
    int m, n = 0, mod = 1000000007, i, j, k, l, r, p;
    long long sum = 0;
    int a[11];
    int b[11];
    
    for (i = 0; i <= 6; i++) {
        comb[i][0] = comb[i][i] = 1;
        
        for (j = 1; j < i; j++) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
    }
    
    scanf("%d", &m);
    
    while (m) {
        a[n++] = m % 10;
        m /= 10;
    }
    
    dp[n][1][0] = 1;
    
    for (i = n; i > 0; i--) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k <= n; k++) {
                if (dp[i][j][k] == 0) continue;
                
                for (l = 0; l < 10; l++) {
                    int c = 0;
                    
                    if (l == 4 || l == 7) c++;
                    
                    if (l < a[i - 1]) {
                        dp[i - 1][0][k + c] += dp[i][j][k];
                    } else if (l == a[i - 1]) {
                        dp[i - 1][j][k + c] += dp[i][j][k];
                    } else {
                        if (j == 0) dp[i - 1][0][k + c] += dp[i][j][k];
                    }
                }
            }
        }
    }
    
    dp[0][0][0]--;
    
    for (i = 0; i <= n; i++) b[i] = dp[0][0][i] + dp[0][1][i];
    
    for (i = n; i > 0; i--) {
        long long x = 0;
        
        if (b[i] == 0) continue;
        
        for (j = 0; j <= 6; j++) {
            for (k = 0; k <= n; k++) {
                for (l = 0; l <= n; l++) {
                    dp2[j][k][l] = 0;
                }
            }
        }
        
        dp2[0][0][0] = 1;
        
        for (j = 0; j < 6; j++) {
            for (k = 0; k < n; k++) {
                for (l = 0; l <= n; l++) {
                    if (dp2[j][k][l] == 0) continue;
                    
                    for (r = 0; r <= 6 - j; r++) {
                        long long y = 1;
                        
                        if (r * k + l > n) continue;
                        
                        if (b[k] < r) continue;
                        
                        for (p = 0; p < r; p++) y = y * (b[k] - p) % mod;
                        
                        y = y * comb[6 - j][r] % mod;
                        
                        dp2[j + r][k + 1][l + r * k] = (dp2[j + r][k + 1][l + r * k] + dp2[j][k][l] * y % mod) % mod;
                    }
                }
            }
        }
        
        for (j = 0; j <= n; j++) {
            for (k = 0; k < i; k++) {
                x = (x + dp2[6][j][k]) % mod;
            }
        }
        
        sum = (sum + b[i] * x % mod) % mod;
    }
    
    printf("%d\n", (int)sum);
    
    return 0;
}