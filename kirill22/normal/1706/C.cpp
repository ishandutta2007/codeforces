#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = (long long) 1e18;
    if (n % 2 == 1) {
        ans = 0;
        for (int i = 1; i < n; i += 2) {
            ans += max(0, max(a[i - 1], a[i + 1]) - a[i] + 1); 
        }
    } else {
        vector<long long> dp(n);
        for (int i = 1; i < n; i++) {
            if (i - 2 >= 0) {
                dp[i] += dp[i - 2];
            }
            dp[i] += max(0, max(a[i - 1], a[i + 1]) - a[i] + 1);
        }
        vector<long long> dp2(n);
        for (int i = n - 2; i >= 0; i--) {
            if (i + 2 < n) {
                dp2[i] += dp2[i + 2];
            }
            dp2[i] += max(0, max(a[i - 1], a[i + 1]) - a[i] + 1);
        }
        for (int i = 0; i < n; i += 2) {
            long long res = 0;
            if (i) {
                res += dp[i - 1];
            }
            if (i + 2 < n) {
                res += dp2[i + 2];
            }
            ans = min(ans, res);
        }
    }
    cout << ans << '\n';
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