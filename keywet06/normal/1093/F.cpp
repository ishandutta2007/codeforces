#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;
const int N = 100005;
const int K = 105;

int n, m, l;
int ra[N];
int freq[K];
int dp[N][K];

int main() {
    scanf("%d %d %d", &n, &m, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ra[i]);
        if (ra[i] < 0) ra[i] = 0;
    }
    if (l == 1) {
        puts("0");
        return 0;
    }
    memset(dp, 0, sizeof(dp));
    memset(freq, 0, sizeof(freq));
    dp[0][0] = 1;
    for (int u = 1; u <= n; u++) {
        ++freq[ra[u - 1]];
        if (ra[u - 1] <= 0) {
            for (int k = 1; k <= m; ++k) dp[u][k] = dp[u - 1][0];
        } else {
            dp[u][ra[u - 1]] = dp[u - 1][0];
        }
        if (u >= l) {
            for (int k = 1; k <= m; ++k) {
                if (freq[0] + freq[k] == l) {
                    dp[u][k] -= (dp[u - l][0] - dp[u - l][k]);
                    dp[u][k] %= P;
                    if (dp[u][k] < 0) dp[u][k] += P;
                }
            }
        }
        for (int k = 1; k <= m; ++k) dp[u][0] = (dp[u][0] + dp[u][k]) % P;
        if (u >= l) --freq[ra[u - l]];
    }
    printf("%d\n", dp[n][0]);
}