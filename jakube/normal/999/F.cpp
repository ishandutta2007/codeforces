#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> c(n * k);
    vector<int> cnt(100'001, 0);
    for (int i = 0; i < n * k; i++) {
        cin >> c[i];
        cnt[c[i]]++;
    }
    map<int, int> cnt2;
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        cnt2[f[i]]++;
    }
    sort(f.begin(), f.end());
    vector<int> h(k+1, 0);
    for (int i = 0; i < k; i++) {
        cin >> h[i+1];
    }

    long long res = 0;
    for (auto [val, player] : cnt2) {
        int total = cnt[val];
        // dp[finished players][remaining]
        vector<vector<long long>> dp(player + 1, vector<long long>(total + 1, 0));
        for (int i = 1; i <= player; i++) {
            for (int rem = 0; rem <= total; rem++) {
                for (int x = 0; x <= k && x <= rem; x++) {
                    dp[i][rem - x] = max(dp[i][rem - x], dp[i-1][rem] + h[x]);
                }
            }
        }
        long long ma = 0;
        for (long long y : dp[player])
            ma = max(ma, y);
        res += ma;
    }
    cout << res << '\n';
}