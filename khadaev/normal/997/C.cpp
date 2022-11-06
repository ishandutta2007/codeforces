#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
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

template<typename T, typename S>
istream& operator>> (istream& in, pair<S, T>& p) {
    in >> p.fs >> p.sn;
    return in;
}
template<typename T, typename S>
ostream& operator<< (ostream& out, pair<S, T>& p) {
    out << p.fs << ' ' << p.sn << ' ';
    return out;
}

template<typename T>
istream& operator>> (istream& in, vector<T>& v) {
    for (T& x : v) in >> x;
    return in;
}
template<typename T>
ostream& operator<< (ostream& out, vector<T>& v) {
    for (T& x : v) out << x << ' ';
    return out;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 998244353;

ll Pow(ll a, ll b) {
    ll x = 1, y = a;
    while (b) {
        if (b % 2) (x *= y) %= MOD;
        (y *= y) %= MOD;
        b /= 2;
    }
    return x;
}

ll Inv(ll x) {
    return Pow(x, MOD - 2);
}

const int N = 1e6 + 10;
ll fact[N], tcaf[N];

void precalc() {
    fact[0] = 1;
    forn(i, 1, N) fact[i] = fact[i - 1] * i % MOD;
    tcaf[N - 1] = Inv(fact[N - 1]);
    ford(i, 0, N - 1) tcaf[i] = tcaf[i + 1] * (i + 1) % MOD;
}

ll binom(int n, int k) {
    return fact[n] * tcaf[k] % MOD * tcaf[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    precalc();
    ll n;
    cin >> n;
    ll ans = 0;
    fore(i, 1, n) {
        ll val = binom((int)n, i) * Pow(3, n * n - n * i + i) % MOD;
        if (i % 2) ans += val;
        else ans -= val;
    }
    ans *= 2;
    ans %= MOD;
    ll tmp = 0;
    fore(i, 1, n) {
        ll q = MOD - Pow(3, MOD - 1 - n + i);
        ll val = Pow(1 + q, n) - 1;
        val *= Pow(3, n * (n - i));
        val %= MOD;
        val *= binom((int)n, i);
        val %= MOD;
        if (i % 2) tmp += val;
        else tmp -= val;
    }
    tmp *= 3;
    tmp %= MOD;
    //cerr << ans << ' ' << tmp << '\n';
    ans += tmp;
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}