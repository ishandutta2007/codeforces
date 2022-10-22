#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool dp[10001][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        ll ans = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            ans += (a[i] * a[i] * (n - 2));
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            sum += b[i];
            ans += (b[i] * b[i] * (n - 2));
        }
        dp[0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= 100 * i; j++) {
                if(dp[j][i]) {
                    dp[j+a[i]][i+1] = 1;
                    dp[j+b[i]][i+1] = 1;
                }
            }
        }
        ll ans2 = 999999999999999999;
        for(int i = 0; i <= 10000; i++) {
            if(dp[i][n]) ans2 = min(ans2, (ll)(sum-i) * (sum-i) + (ll)(i * i));
        }
        cout << ans + ans2 << '\n';
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= 100 * n; j++) {
                dp[j][i] = 0;
            }
        }
    }
}