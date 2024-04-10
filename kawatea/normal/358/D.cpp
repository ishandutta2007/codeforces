#include <cstdio>
#include <algorithm>

using namespace std;

int dp[3001][2];

int main()
{
    int n, i, j;
    int a[3000];
    int b[3000];
    int c[3000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) scanf("%d", &b[i]);
    for (i = 0; i < n; i++) scanf("%d", &c[i]);
    
    c[0] = b[0];
    c[n - 1] = b[n - 1];
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j < 2; j++) {
            dp[i][j] = -1;
        }
    }
    
    dp[0][0] = 0;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2; j++) {
            if (dp[i][j] == -1) continue;
            
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + b[i]);
            
            if (j == 0) {
                dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + a[i]);
            } else {
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + c[i]);
            }
        }
    }
    
    printf("%d\n", dp[n][1]);
    
    return 0;
}