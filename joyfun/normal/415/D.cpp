#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const __int64  MOD  = 1000000007;
const int N = 2005;
__int64 n, K, dp[N][N];
#include <math.h>

int main() {
    int i, j, k;
    memset(dp, 0, sizeof(dp));
        dp[0][1] = 1;
    scanf("%I64d%I64d", &n, &K);
    for (i = 1; i <= K; i++) {
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= (int)sqrt((double)j); k++) {
                if (j % k != 0) continue;
                if (k != j/k) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k] + dp[i - 1][j/k]) % MOD;
                }
                else dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }
    __int64 ans = 0;
    for (i = 1; i <= n; i++) {
        ans = (ans + dp[K][i]) % MOD;
    }
    printf("%I64d\n", ans);
    return 0;
}