#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
const ll mod = 998244353;

ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}


ll a[N];
ll dp[N];

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll cnt = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 0) cnt++;
        }
        ll now = 0;
        for (ll i = 1; i <= cnt; i++) {
            if (a[i] == 1) now++;
        }
        ll tot = n * (n - 1) % mod * qpow(2, mod - 2) % mod;
        dp[0] = 0;
        for (ll i = 1; i <= now; i++) {
            dp[i] = (tot * qpow(i * i % mod, mod - 2) % mod + dp[i - 1]) % mod;
        }
        cout << dp[now] << endl;
    }
}