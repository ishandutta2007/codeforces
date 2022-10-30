#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int a[20];
int b[20];

int get(int x)
{
    int sum = 0, i;
    int c[20] = {0};
    
    for (i = 0; i < n; i++) sum += a[i] * (m - 2);
    
    while (x) {
        int y = -1e9, z;
        
        for (i = 0; i < n; i++) {
            if (c[i] == 1) continue;
            
            if (a[i] - b[i] > y) {
                y = a[i] - b[i];
                z = i;
            }
        }
        
        c[z] = 1;
        
        sum -= min(m - 2, x) * y;
        x -= min(m - 2, x);
    }
    
    return sum;
}

int main()
{
    int ans = 2e9, i, j;
    int dp[21][21];
    int dp2[21][21];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) scanf("%d", &b[i]);
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            dp[i][j] = 2e9;
        }
    }
    
    dp[0][0] = 0;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            if (dp[i][j] == 2e9) continue;
            
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + a[i]);
            
            if (j > 0) dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + b[i]);
        }
    }
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            dp2[i][j] = 2e9;
        }
    }
    
    dp2[n][0] = 0;
    
    for (i = n; i > 0; i--) {
        for (j = 0; j <= n; j++) {
            if (dp2[i][j] == 2e9) continue;
            
            dp2[i - 1][j + 1] = min(dp2[i - 1][j + 1], dp2[i][j] + b[i - 1]);
            
            if (j > 0) dp2[i - 1][j - 1] = min(dp2[i - 1][j - 1], dp2[i][j] + a[i - 1]);
        }
    }
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            int x = n * m / 2;
            
            if (dp[n][i] == 2e9 || dp2[0][j] == 2e9) continue;
            
            x -= (n - i) / 2;
            x -= (n + j) / 2;
            
            if (x < 0 || x > n * (m - 2)) continue;
            
            ans = min(ans, dp[n][i] + dp2[0][j] + get(x));
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}