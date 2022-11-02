#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, len;
    cin >> n >> k >> len;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        a[i] = isupper(c);
    }
    auto solve = [&]() {
        int sum = accumulate(a.begin(), a.end(), 0);
        vector<int> pre(n + 1);
        vector<pair<int, int>> dp(n + 1);
        for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] + a[i];
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r + 1) / 2;
            for (int i = 1; i <= n; ++i) {
                int j = max(0, i - len);
                dp[i] =
                    max(dp[i - 1], make_pair(dp[j].first + pre[i] - pre[j] - m,
                                             dp[j].second + 1));
            }
            if (dp[n].second >= k) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            int j = max(0, i - len);
            dp[i] = max(dp[i - 1], make_pair(dp[j].first + pre[i] - pre[j] - l,
                                             dp[j].second + 1));
        }
        return sum - dp[n].first - l * k;
    };
    int ans = solve();
    for (int i = 0; i < n; ++i) a[i] = 1 - a[i];
    ans = min(ans, solve());
    cout << ans << "\n";
    return 0;
}