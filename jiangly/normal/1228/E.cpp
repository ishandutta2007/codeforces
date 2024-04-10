#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
constexpr int MAX_N = 250, MOD = 1e9 + 7;
int n, k;
int dp[2][MAX_N + 1];
int C[MAX_N + 1][MAX_N + 1], pw[MAX_N + 1], pwk[MAX_N + 1];
void solve(int case_id) {
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
    pw[0] = 1;
    for (int i = 1; i <= n; ++i)
        pw[i] = 1ll * pw[i - 1] * (k - 1) % MOD;
    pwk[0] = 1;
    for (int i = 1; i <= n; ++i)
        pwk[i] = 1ll * pwk[i - 1] * k % MOD;
    int cur = 0;
    dp[cur][0] = 1;
    for (int i = 0; i < n; ++i) {
        cur ^= 1;
        memset(dp[cur], 0, (n + 1) * sizeof(int));
        for (int j = 0; j <= n; ++j)
            for (int k = j; k <= n; ++k)
                dp[cur][k] = (dp[cur][k] + 1ll * dp[cur ^ 1][j] * C[n - j][k - j] % MOD * pw[n - k] % MOD * (pwk[j] + (j == k ? MOD - pw[j] : 0))) % MOD;
    }
    cout << dp[cur][n] << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i)
        solve(i);
    return 0;
}