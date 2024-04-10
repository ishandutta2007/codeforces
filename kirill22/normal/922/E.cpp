#include<bits/stdc++.h>

using namespace std;

long long dp[1001][10001];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, W, B, X, ans = 0, s = 0;
    cin >> n >> W >> B >> X;
    vector<long long> cnt(n), cost(n);
    for (int i = 0; i < n; i++) cin >> cnt[i], s += cnt[i];
    for (int i = 0; i < n; i++) cin >> cost[i];
    for (int i = 0; i <= n; i++) for (int j = 0; j <= s; j++) dp[i][j] = -1;
    dp[0][0] = W;
    for (int i = 1; i <= n; i++) {
        for (long long j = 0; j <= s; j++) {
            for (long long k = 0; k <= min(cnt[i - 1], j); k++) {
                if (dp[i - 1][j - k] == -1) continue;
                long long res = min(dp[i - 1][j - k] + X, W + B * (j - k)) - cost[i - 1] * k;
                if (res < 0) continue;
                ans = max(ans, j);
                dp[i][j] = max(res, dp[i][j]);
            }
        }
    }
    cout << ans;
}