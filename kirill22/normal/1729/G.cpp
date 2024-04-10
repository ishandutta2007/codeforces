#include "bits/stdc++.h"

using namespace std;

const int mod = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = (int) s.size(), m = (int) t.size();
    vector<int> a(n);
    for (int i = 0; i + m - 1 < n; i++) {
        if (s.substr(i, m) == t) {
            a[i] = 1;
        }
    }
    vector<pair<int, int>> dp(n + 1, {n + 1, 0});
    dp[n] = {0, 1};
    for (int i = n - 1; i >= 0; i--) {
        if (!a[i]) {
            dp[i] = dp[i + 1];
            continue;
        }
        for (int j = i; j <= i + m - 1; j++) {
            if (a[j]) {
                auto res = dp[j + m];
                res.first++;
                if (dp[i].first > res.first) {
                    dp[i] = res;
                } else if (dp[i].first == res.first) {
                    (dp[i].second += res.second) %= mod;
                }
            }
        }
    }
    cout << dp[0].first << " " << dp[0].second << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}