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

int good(vector<int>& a, int x) {
    int ans = 0;
    for (int i : a)
        if (i > x && i <= 2 * x)
            ++ans;
    return ans;
}

ll c2(ll x) {return x * (x - 1) / 2;}
ll c3(ll x) {return x * (x - 1) * (x - 2) / 6;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int g, d, f;
    cin >> g >> d >> f;
    vector<int> gs(g), ds(d), fs(f);
    cin >> gs >> ds >> fs;
    ll ans = 0;
    for (int x : gs) {
        ll _d = good(ds, x), _f = good(fs, x);
        ans += c2(_d) * c3(_f);
    }
    for (int x : ds) {
        ll _g = good(gs, x), _d = good(ds, x), _f = good(fs, x);
        ans += _g * _d * c3(_f);
    }
    for (int x : fs) {
        ll _g = good(gs, x), _d = good(ds, x), _f = good(fs, x);
        ans += _g * c2(_d) * c2(_f);
    }
    cout << ans << '\n';
}