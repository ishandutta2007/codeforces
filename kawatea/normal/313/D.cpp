#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[301][301];

int main()
{
    int n, m, k, i, j, l;
    long long ans = 1e18;
    long long a[300][300];
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = 1e18;
        }
    }
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        a[x - 1][y - 1] = min(a[x - 1][y - 1], (long long)z);
    }
    
    for (i = 0; i < n; i++) {
        for (j = n - 2; j >= 0; j--) {
            a[i][j] = min(a[i][j], a[i][j + 1]);
        }
    }
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            dp[i][j] = 1e18;
        }
    }
    
    dp[0][0] = 0;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            if (dp[i][j] == 1e18) continue;
            
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            
            for (l = i; l < n; l++) {
                if (a[i][l] == 1e18) continue;
                
                dp[l + 1][j + l - i + 1] = min(dp[l + 1][j + l - i + 1], dp[i][j] + a[i][l]);
            }
        }
    }
    
    for (i = k; i <= n; i++) ans = min(ans, dp[n][i]);
    
    if (ans == 1e18) ans = -1;
    
    printf("%I64d\n", ans);
    
    return 0;
}