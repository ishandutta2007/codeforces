#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[101][2];

int main()
{
    int n, k, d, m = 1000000007, i, j, l, r;
    
    scanf("%d %d %d", &n, &k, &d);
    
    dp[0][0] = 1;
    
    for (i = 0; i < n; i++) {
        for (j = n - 1; j >= 0; j--) {
            for (l = 0; l < 2; l++) {
                if (dp[j][l] == 0) continue;
                
                for (r = 1; r <= k; r++) {
                    if (j + r > n) break;
                    
                    if (r >= d) {
                        dp[j + r][1] += dp[j][l];
                        if (dp[j + r][1] >= m) dp[j + r][1] -= m;
                    } else {
                        dp[j + r][l] += dp[j][l];
                        if (dp[j + r][l] >= m) dp[j + r][l] -= m;
                    }
                }
                
                dp[j][l] = 0;
            }
        }
    }
    
    printf("%I64d\n", dp[n][1]);
    
    return 0;
}