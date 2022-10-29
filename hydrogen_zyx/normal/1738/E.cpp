#include <cstring>
#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
const ll mod = 998244353;

ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

ll fac[N], inv[N];

ll c(ll n, ll m) {
    if (n < m || n < 0 || m < 0) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fac[0] = 1;
    for (ll i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
    inv[N - 1] = qpow(fac[N - 1], mod - 2);
    for (ll i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a0, a1, b0, b1;
        ll now = 0;
        for (ll i = 1; i <= n; i++) {
            ll tmp;
            cin >> tmp;
            if (tmp == 0) {
                now++;
            } else {
                a0.push_back(now);
                a1.push_back(tmp);
                b0.push_back(now);
                b1.push_back(tmp);
                now = 0;
            }
        }
        a0.push_back(now), b0.push_back(now);
        if (a1.size() == 0) {
            cout << qpow(2, a0[0] - 1) << endl;
            continue;
        }
        reverse(b0.begin(), b0.end());
        reverse(b1.begin(), b1.end());

        ll posa = 1, posb = 1;
        ll nowa = a1[0], nowb = b1[0];
        vector<ll> ps;
        while (1) {
            if (nowa == nowb) ps.push_back(posa - 1);
            if (posa >= a1.size() && posb >= b1.size()) break;
            if (nowa <= nowb) nowa += a1[posa], posa++;
            else nowb += b1[posb], posb++;
        }
        vector<ll> v;
        v.push_back(a0[0]);
        for (auto x: ps) v.push_back(a0[x + 1]);
        ll pos1 = 0, pos2 = v.size() - 1;
        ll ans = 1;
        while (pos1 <= pos2) {
            ll cnt = 0;
            if (pos1 == pos2) {
                for (ll i = 0; i <= v[pos1] + 1; i++) {
                    cnt = (cnt + c(v[pos1] + 1, i)) % mod;
                }
            } else if (pos1 == 0) {
                for (ll i = 0; i <= min(v[pos1], v[pos2]); i++) {
                    cnt = (cnt + c(v[pos1], i) * c(v[pos2], i)) % mod;
                }
            } else {
                for (ll i = 0; i <= min(v[pos1], v[pos2]) + 1; i++) {
                    cnt = (cnt + c(v[pos1] + 1, i) * c(v[pos2] + 1, i)) % mod;
                }
            }
            ans = ans * cnt % mod;
            pos1++, pos2--;
        }
        cout << ans << endl;
    }
}