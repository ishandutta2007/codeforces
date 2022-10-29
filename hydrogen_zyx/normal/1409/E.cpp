#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[300000];
ll dp[300000][2];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t, n;
    cin >> t;
    while (t--) {
        ll k;
        cin >> n >> k;
        for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = 0;
        for (int i = 1; i <= n; i++) cin >> x[i];
        ll a;
        for (int i = 1; i <= n; i++) cin >> a;
        sort(x + 1, x + 1 + n);
        ll p = 1;
        for (int i = 1; i <= n; i++) {
            while (x[i] - x[p] > k) p++;
            dp[i][0] = max(dp[i - 1][0], i - p + 1);
            dp[i][1] = max(dp[i - 1][1], dp[p - 1][0] + i - p + 1);
        }
        cout << dp[n][1] << endl;
    }
}