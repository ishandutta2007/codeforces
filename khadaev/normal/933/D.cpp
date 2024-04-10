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
const ll MOD = 1000000007;

int root(ll x) {
    int ans = (int)sqrt(x);
    while (1ll * ans * ans <= x) ++ans;
    while (1ll * ans * ans > x) --ans;
    return ans;
}

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

ll INV210 = Inv(210);

struct Mod {
    ll x;

    Mod () {}

    Mod (ll _x) {
        x = _x % MOD;
        if (x < 0) x += MOD;
    }

    Mod operator+ (Mod rhs) {
        ll ans = x + rhs.x;
        if (ans >= MOD) ans -= MOD;
        Mod ret; ret.x = ans; return ret;
    }

    Mod operator- (Mod rhs) {
        ll ans = x - rhs.x;
        if (ans < 0) ans += MOD;
        Mod ret; ret.x = ans; return ret;
    }

    Mod operator* (Mod rhs) {
        Mod ret; ret.x = x * rhs.x % MOD; return ret;
    }

    Mod operator+= (Mod rhs) {
        x += rhs.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }

    Mod operator-= (Mod rhs) {
        x -= rhs.x;
        if (x < 0) x += MOD;
        return *this;
    }

    Mod operator*= (Mod rhs) {
        x *= rhs.x;
        x %= MOD;
        return *this;
    }

    Mod operator^ (ll a) {
        Mod ret; ret.x = Pow(x, a); return ret;
    }

    Mod operator^= (ll a) {
        x = Pow(x, a);
        return *this;
    }

    Mod inv() {
        Mod ret; ret.x = Inv(x); return ret;
    }

    Mod operator/ (Mod rhs) {
        return *this * rhs.inv();
    }

    Mod operator/= (Mod rhs) {
        *this *= rhs.inv();
        return *this;
    }
};

Mod operator+ (ll a, Mod b) {
    return Mod(a) + b;
}

Mod operator- (ll a, Mod b) {
    return Mod(a) - b;
}

Mod operator* (ll a, Mod b) {
    return Mod(a) * b;
}

ll get(ll _x, ll _t, ll _m) {
    Mod x = Mod(_x), t = Mod(_t), m = Mod(_m);
    auto t2 = t * t, t3 = t2 * t, t4 = t3 * t, t5 = t4 * t, t6 = t5 * t;
    auto m2 = m * m, m3 = m2 * m;
    auto x2 = x * x, x4 = x2 * x2;
    auto ans = (2 * t + 1) * (35 * m3 + 105 * m2 - 7 * m * (3 * t4 + 6 * t3 + t2 * (10 * x2 - 3)
            + 2 * t * (5 * x2 - 3) + 5 * (3 * x4 - 3 * x2 - 2)) + 2 * (5 * t6 + 15 * t5 + t4 * (21 * x2 - 11) +
            t3 * (42 * x2 - 47)
            + t2 * (35 * x4 - 56 * x2 + 6) + t * (35 * x4 - 77 * x2 + 32) + 35 * x2 * (x4 - 3 * x2 + 2)));
    ans = ans *  Mod(INV210);
    return ans.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    ll m;
    cin >> m;
    ll ans = 0;
    int max_x = root(m);
    for (ll x = -max_x; x <= max_x; ++x) {
        ll t = root(m - x * x);
        //cerr << x << ' ' << t << '\n';
        //cerr << get(x, t, m) << '\n';
        ans += get(x, t, m);
        ans %= MOD;
    }
    cout << ans << '\n';
}