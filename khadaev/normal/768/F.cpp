#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const ll INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1e5 + 10;

ll fact[N], invfact[N];

ll Pow(ll a, ll b) {
    ll x = 1, y = a;
    while (b) {
        if (b % 2) x = x * y % MOD;
        y = y * y % MOD;
        b /= 2;
    }
    return x;
}

ll Inv(ll a) {
    return Pow(a, MOD - 2);
}

ll cnt(ll sum, ll _cnt) {
    if (sum == 0 && _cnt == 0) return 1;
    if (sum < 0 || _cnt < 1) return 0;
    return fact[sum + _cnt - 1] * invfact[sum] % MOD * invfact[_cnt - 1] % MOD;
}

ll p = 0, q = 0;
ll f, w, h;

void add(ll cf, ll cw, ll coeff) {
    ll cnt1 = cnt(f - cf, cf);
    q += coeff * cnt1 * cnt(w - cw, cw);
    q %= MOD;
    p += coeff * cnt1 * cnt(w - (h + 1) * cw, cw);
    p %= MOD;
}

void precalc() {
    fact[0] = 1;
    forn(i, 1, N) fact[i] = fact[i - 1] * i % MOD;
    invfact[N - 1] = Inv(fact[N - 1]);
    ford(i, 0, N - 1) invfact[i] = invfact[i + 1] * (i + 1) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    precalc();
    cin >> f >> w >> h;
    fore(i, 0, min(w, f) + 2) {
        add(i + 1, i, 1);
        add(i, i + 1, 1);
        add(i, i, 2);
    }
    //cout << p << ' ' << q << '\n';
    cout << p * Inv(q) % MOD << '\n';
}