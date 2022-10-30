#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];
int b[100000];
int dp[100001][2];

int main()
{
    int n, m, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) scanf("%1d", &b[i]);
    
    for (i = 0; i <= n; i++) dp[i][0] = dp[i][1] = -1;
    
    dp[0][0] = 0;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2; j++) {
            if (dp[i][j] == -1) continue;
            
            if (j == 0) {
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + a[n - i - 1] * b[n - i - 1]);
                if (b[n - i - 1] == 1) dp[i + 1][1] = max(dp[i + 1][1], dp[i][j]);
            } else {
                dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + a[n - i - 1]);
            }
        }
    }
    
    printf("%d\n", max(dp[n][0], dp[n][1]));
    
    return 0;
}