#include <cstdio>

using namespace std;

int a[500];
long long c[501][501];
long long dp[2][501][501];

int main()
{
    int n, m, mod, x = 0, y = 0, i, j, k;
    
    scanf("%d %d %d", &n, &m, &mod);
    
    for (i = 0; i < m; i++) {
        char s[501];
        
        scanf("%s", s);
        
        for (j = 0; j < n; j++) {
            if (s[j] == '1') a[j]++;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] == 0) {
            x++;
        } else if (a[i] == 1) {
            y++;
        }
    }
    
    for (i = 0; i <= n; i++) {
        c[i][0] = c[i][i] = 1;
        
        for (j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    
    dp[m & 1][x][y] = 1;
    
    for (i = m; i < n; i++) {
        for (j = 0; j <= n; j++) {
            for (k = 0; k <= n; k++) {
                if (dp[i & 1][j][k] == 0) continue;
                
                if (j >= 2) {
                    dp[(i + 1) & 1][j - 2][k + 2] = (dp[(i + 1) & 1][j - 2][k + 2] + dp[i & 1][j][k] * c[j][2] % mod) % mod;
                }
                
                if (j >= 1 && k >= 1) {
                    dp[(i + 1) & 1][j - 1][k] = (dp[(i + 1) & 1][j - 1][k] + dp[i & 1][j][k] * j % mod * k % mod) % mod;
                }
                
                if (k >= 2) {
                    dp[(i + 1) & 1][j][k - 2] = (dp[(i + 1) & 1][j][k - 2] + dp[i & 1][j][k] * c[k][2] % mod) % mod;
                }
                
                dp[i & 1][j][k] = 0;
            }
        }
    }
    
    printf("%d\n", dp[n & 1][0][0]);
    
    return 0;
}