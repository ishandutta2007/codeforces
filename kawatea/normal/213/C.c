#include <stdio.h>

int max(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int a[300][300];
int dp[2][300][300];
int dp2[2][300][300];

int main()
{
    int n, ans = -1e9, p, q, i, j, k;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    if (n == 1) {
        printf("%d\n", a[0][0]);
        
        return 0;
    }
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                dp[i][j][k] = dp2[i][j][k] = -1e9;
            }
        }
    }
    
    dp[0][0][0] = a[0][0];
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j <= i; j++) {
            for (k = 0; k <= i; k++) {
                if (dp[i % 2][j][k] == -1e9) continue;
                
                for (p = 0; p <= 1; p++) {
                    for (q = 0; q <= 1; q++) {
                        int x = j + p;
                        int y = k + q;
                        int z = 0;
                        
                        if (x > y) {
                            int tmp = x;
                            x = y;
                            y = tmp;
                        }
                        
                        z += a[i + 1 - x][x];
                        z += a[i + 1 - y][y];
                        
                        if (x == y) z -= a[i + 1 - x][x];
                        
                        dp[(i + 1) % 2][x][y] = max(dp[(i + 1) % 2][x][y], dp[i % 2][j][k] + z);
                    }
                }
                
                dp[i % 2][j][k] = -1e9;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i + j >= n - 1) continue;
            
            a[i][j] = a[n - j - 1][n - i - 1];
        }
    }
    
    dp2[0][0][0] = a[0][0];
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j <= i; j++) {
            for (k = 0; k <= i; k++) {
                if (dp2[i % 2][j][k] == -1e9) continue;
                
                for (p = 0; p <= 1; p++) {
                    for (q = 0; q <= 1; q++) {
                        int x = j + p;
                        int y = k + q;
                        int z = 0;
                        
                        if (x > y) {
                            int tmp = x;
                            x = y;
                            y = tmp;
                        }
                        
                        z += a[i + 1 - x][x];
                        z += a[i + 1 - y][y];
                        
                        if (x == y) z -= a[i + 1 - x][x];
                        
                        if (i == n - 2) z = 0;
                        
                        dp2[(i + 1) % 2][x][y] = max(dp2[(i + 1) % 2][x][y], dp2[i % 2][j][k] + z);
                    }
                }
                
                dp2[i % 2][j][k] = -1e9;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ans = max(ans, dp[(n - 1) % 2][i][j] + dp2[(n - 1) % 2][i][j]);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}