#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        vector<int> dp(n), dp2(n);
        dp[0] = a + b;
        dp2[0] = 1e18;
        for (int i = 1; i < n; i++) {
            if ( (i > 0 && s[i - 1] == '1') || s[i] == '1') {
                dp[i] = 1e18;
                dp2[i] = min(dp2[i - 1] + 2 * b + a, dp[i - 1] + 2 * a + 2 * b);
            }
            else {
                dp[i] = min(dp2[i - 1] + 2 * a + b, dp[i - 1] + a + b);
                dp2[i] = min(dp2[i - 1] + 2 * b + a, dp[i - 1] + 2 * a + 2 * b);
            }
        }
        cout << min(dp[n - 1] + b, dp2[n - 1] + a + b) << endl;
    }
}