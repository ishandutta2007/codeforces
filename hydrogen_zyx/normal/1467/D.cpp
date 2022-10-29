#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const double dinf = 1e99;
const ll inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
ll dp[5005][5005];
ll a[N];
ll xi[N];

int main() {
    ios::sync_with_stdio(false);
    ll n, k, q;
    cin >> n >> k >> q;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll i = 1; i <= n; i++) dp[0][i] = 1;
    for (ll i = 1; i <= k; i++) {
        for (ll j = 1; j <= n; j++) {
            if (j - 1 >= 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
            if (j + 1 <= n) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
        }
    }
    for (ll j = 1; j <= n; j++) {
        for (ll i = 0; i <= k; i++) {
            xi[j] = (xi[j] + dp[i][j] * dp[k - i][j]) % mod;
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++) ans = (ans + xi[i] * a[i]) % mod;
    for (ll i = 1; i <= q; i++) {
        ll pos, x;
        cin >> pos >> x;
        ll add = x - a[pos];
        if (add < 0) add += mod;
        a[pos] = x;
        ans = (ans + add * xi[pos]) % mod;
        cout << ans << endl;
    }
}