#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    vector<int> pref(n + 1);
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = max(dp[i - 1], a[i - 1] + pref[i - 1] - dp[i - 1]);
    }
    cout << pref[n] - dp[n] << ' ' << dp[n] << endl;
}