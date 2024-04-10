#include<bits/stdc++.h>

using namespace std;

unordered_map<long long, int> dp;
vector<int> a, pref;
int n;

long long hashmy(long long d1, long long d2, long long k) {
    return k + d1 * (n + 2202ll) + d2 * (n + 2202ll) * (n + 2202ll);
}

int solve(int d1, int d2, int k) {
    if (n - d1 - d2 < k) return 0;
    long long h = hashmy(d1, d2, k);
    if (dp.find(h) == dp.end()) {
        dp[h] = -1e9;
        for (int l = k; l <= k + 1; l++) {
            int f = 1e9;
            if (n - d1 - d2 < l) continue;
            if (d1 + d2 + l + l > n) {
                dp[h] = max(dp[h], pref[d1 + l] - pref[d1]);
                continue;
            }
            for (int r = l; r <= l + 1; r++) {
                int res = pref[d1 + l] - pref[d1];
                if (l + d1 + d2 + r <= n) {
                    int st = (n - d2 - 1) - r + 1;
                    res -= pref[st + r] - pref[st];
                    f = min(f, res + solve(d1 + l, d2 + r, r));
                }
                else continue;
            }
            dp[h] = max(dp[h], f);
        }
    }
    return dp[h];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n);
    pref.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
    cout << solve(0, 0, 1);
}