#include <cstdio>
#include <algorithm>

using namespace std;

long long a[501];
long long b[501];
long long dp[2][501][501];

int main()
{
    int n, k, m = 1000000007, i, j, l;
    long long ans = 0;
    
    scanf("%d %d", &n, &k);
    
    a[0] = 1;
    for (i = 1; i <= 500; i++) a[i] = a[i - 1] * 2 % m;
    for (i = 1; i <= 500; i++) {
        b[i] = a[i] - 1;
        if (b[i] < 0) b[i] += m;
    }
    
    dp[1][0][0] = 1;
    
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= k; j++) {
            for (l = 0; l < i; l++) {
                if (dp[i & 1][j][l] == 0) continue;
                
                dp[(i + 1) & 1][j][l] = (dp[(i + 1) & 1][j][l] + dp[i & 1][j][l] * a[l] % m) % m;
                dp[(i + 1) & 1][j + 1][i] = (dp[(i + 1) & 1][j + 1][i] + dp[i & 1][j][l] * a[l] % m * b[i - l] % m) % m;
                
                dp[i & 1][j][l] = 0;
            }
        }
    }
    
    for (i = 0; i <= n; i++) ans += dp[(n + 1) & 1][k][i];
    ans %= m;
    
    printf("%I64d\n", ans);
    
    return 0;
}