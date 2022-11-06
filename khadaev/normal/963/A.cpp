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
const ll MOD = 1000000009;

ll Pow(ll a, ll b) {
    ll x = 1, y = a;
    while (b) {
        if (b % 2) (x *= y) %= MOD;
        (y *= y) %= MOD;
        b /= 2;
    }
    return x;
}

ll Inv(ll a) {
    return Pow(a, MOD - 2);
}

ll geom(ll q, ll n) {
    if (q == 1) return n + 1;
    return (Pow(q, n + 1) + MOD - 1) * Inv(q + MOD - 1) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    ll n, a, b;
    int k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    vector<ll> x(k);
    forn(i, 0, k) x[i] = s[i] == '+' ? +1 : MOD-1;
    ll pw = 1;
    forn(i, 0, k) {
        (x[i] *= pw) %= MOD;
        (pw *= b) %= MOD; 
    }
    pw = 1;
    ford(i, 0, k) {
        (x[i] *= pw) %= MOD;
        (pw *= a) %= MOD;
    }
    ll sum = 0;
    forn(i, 0, k) sum += x[i];
    sum %= MOD;
    ll st = Pow(a, n + 1 - k);
    ll q = Pow(b, k) * Pow(Inv(a), k) % MOD;
    cout << st * geom(q, (n + 1) / k - 1) % MOD * sum % MOD << '\n';
}