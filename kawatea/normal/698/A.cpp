#include <cstdio>
#include <algorithm>

using namespace std;

int a[100];
int dp[101][3];

int main() {
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j < 3; j++) {
            dp[i][j] = -1;
        }
    }
    
    dp[0][0] = 0;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            if (dp[i][j] == -1) continue;
            
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
            if (j != 1 && a[i] % 2 == 1) dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + 1);
            if (j != 2 && a[i] >= 2) dp[i + 1][2] = max(dp[i + 1][2], dp[i][j] + 1);
        }
    }
    
    printf("%d\n", n - max(dp[n][0], max(dp[n][1], dp[n][2])));
    
    return 0;
}