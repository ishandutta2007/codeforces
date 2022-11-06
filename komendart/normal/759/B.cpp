#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = -100500;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x = dp[upper_bound(a.begin(), a.end(), a[i] - 1) - a.begin() - 1];
        int y = dp[upper_bound(a.begin(), a.end(), a[i] - 90) - a.begin() - 1];
        int z = dp[upper_bound(a.begin(), a.end(), a[i] - 1440) - a.begin() - 1];
        dp[i] = min({x + 20, y + 50, z + 120});
        cout << dp[i] - dp[i - 1] << '\n';
    }

}