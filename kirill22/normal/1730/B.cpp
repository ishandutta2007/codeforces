#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i].second;
    }
    sort(x.begin(), x.end());
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = x[i].second - x[i].first;
        if (i) {
            dp[i] = max(dp[i], dp[i - 1]);
        }
    }
    if (n == 1) {
        cout << x[0].first << '\n';
        return;
    }
    long double res = -2e9, tmp = 2e9;
    long double ans;
    for (int i = n - 1; i > 0; i--) {
        res = max(res, (long double) x[i].first + x[i].second);
        long double X = (long double) (res - dp[i - 1]) / 2;
        X = max(X, (long double) x[i - 1].first);
        X = min(X, (long double) x[i].first);
        long double res2 = max(dp[i - 1] + X, res - X);
        if (res2 < tmp) {
            tmp = res2;
            ans = X;
        }
    }
    cout << fixed << setprecision(15) << ans << '\n';
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