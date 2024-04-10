#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n) - 1; i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
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

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
//const int INF = 2000000000;
const ll INF = 1ll << 32;
//const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

map<int, int> memo;
int phi(int n) {
    auto it = memo.find(n);
    if (it != memo.end()) return it->second;
    int _n = n;
    int ans = 1;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            n /= p;
            ans *= p - 1;
            while (n % p == 0) {
                n /= p;
                ans *= p;
            }
        }
    }
    if (n != 1) ans *= n - 1;
    return memo[_n] = ans;
}

ll Pow(ll a, ll b, ll mod) {
    ll x = 1, y = a % mod;
    while (b) {
        if (b & 1) (x *= y) %= mod;
        (y *= y) %= mod;
        b /= 2;
    }
    return x % mod;
}

pair<ll, ll> get(int l, int r, vector<int>& w, int mod) {
    if (l == r || w[l] == 1) return {1 % mod, 1};
    if (l + 1 == r) return {w[l] % mod, w[l]};
    if (mod == 1) {
        int ok = 1;
        for (int i = l; i < r && i < l + 6; ++i)
            if (w[i] == 1)
                ok = false;
        if (ok) return {0, INF};
    }
    int m1 = 1, m2 = mod;
    while (1) {
        int g = __gcd(m2, w[l]);
        if (g == 1) break;
        m1 *= g;
        m2 /= g;
    }
    int ph = phi(m2);
    //cerr << "phi: " << m2 << ' ' << ph << '\n';
    pair<ll, ll> nxt = get(l + 1, r, w, ph);
    //cerr << "nxt: " << nxt.fs << ' ' << nxt.sn << '\n';
    if (nxt.sn > 32) {
        ll common = 0, coprime = Pow(w[l], nxt.fs, m2);
        ll t = ((coprime - common) % m2 + m2) * Pow(m1, ph - 1, m2) % m2;
        ll ans = t * m1 + common;
        return {ans % mod, INF};
    }
    ll common = 1;
    ll real = 1;
    ll its = nxt.sn;
    while (its--) {
        (common *= w[l]) %= m1;
        if (real < INF) real *= w[l];
    }
    common %= m1;
    if (real > INF) real = INF;
    ll coprime = Pow(w[l], nxt.fs, m2);
    ll t = ((coprime - common) % m2 + m2) * Pow(m1, ph - 1, m2) % m2;
    ll ans = t * m1 + common;
    //cerr << "debug\n";
    //cerr << mod << '\n';
    //cerr << m1 << ' ' << m2 << '\n';
    //cerr << coprime << ' ' << common << '\n';
    //cerr << t << '\n';
    //assert(Pow(m1, ph, m2) % m2 == 1 % m2);
    assert(ans % m1 == common % m1);
    assert(ans % m2 == coprime % m2);
    //cerr << l << ' ' << r << ' ' << mod << '\n';
    //cerr << ans << ' ' << real << '\n';
    return {ans % mod, real};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    forn(i, 0, n) cin >> w[i];
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << get(--l, r, w, m).fs << '\n';
    }
}