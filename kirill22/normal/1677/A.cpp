#include<bits/stdc++.h>
 
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
            a[i]--;
        }
        vector<vector<int>> dp(n + 1, vector<int> (n));
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i];
            for (int j = a[i]; j < n; j++) {
                dp[i + 1][j]++;
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += dp[i][a[j]] * 1ll * (a[i] + 1 - dp[j + 1][a[i]]);
            }
        }
        cout << ans << '\n';
    }
}