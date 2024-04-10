#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= n; i++) {
            if (i > 0 && a[i - 1] <= i - 1 && dp[i - a[i - 1] - 1]) {
                dp[i] = 1;
            }
            if (i < n && i + a[i] + 1 <= n) {
                if (dp[i]) {
                    dp[i + a[i] + 1] = 1;
                }
            }
            //for (auto x : dp) {
            //    cout << x << " ";
            //}
            //cout << endl;
        }
        cout << (dp[n] ? "YES\n" : "NO\n");
    }
}