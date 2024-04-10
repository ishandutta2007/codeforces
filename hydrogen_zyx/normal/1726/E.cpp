#include<bits/stdc++.h>

using namespace std;

#define pii pair<ll,ll>
#define fi first
#define se second
#define de(x) cout<< #x << ' ' << x << endl;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

ll dp[N];
ll pow2[N];
ll fac[N], inv[N];
ll pi[N];

ll C(ll n, ll m) {
    if (n < m || n < 0 || m < 0) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fac[0] = 1;
    for (ll i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
    inv[N - 1] = qpow(fac[N - 1], mod - 2);
    for (ll i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
    dp[0] = dp[1] = 1;
    pow2[0] = 1, pow2[1] = 2;
    pi[0] = 1, pi[1] = 0;
    for (ll i = 2; i < N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * (i - 1)) % mod;
        pow2[i] = pow2[i - 1] * 2 % mod;
        pi[i] = pi[i - 2] * (i - 1) % mod;
    }
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll ans = 0;
        for (ll i = 0; i * 4 <= n; i++) {
            ll num = i * 2;
            ans = (ans + C(n - num, num) * pi[num] % mod * pow2[i] % mod * dp[n - 4 * i] % mod) % mod;
        }
        cout << ans << endl;
    }
}