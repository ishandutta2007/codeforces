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

ll highest(ll x) {
    ford(i, 0, 61)
        if (x & (1ll << i))
            return i;
    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    vector<ll> b(n);
    cin >> b;
    vector<vector<ll>> bit(61);
    for (ll x : b)
        bit[highest(x)].eb(x);
    vector<ll> ans;
    ford(i, 0, 61) {
        vector<ll> tmp;
        auto it = bit[i].begin();
        ll cur = 0;
        if (it != bit[i].end()) {
            cur ^= *it;
            tmp.eb(*it);
            ++it;
        }
        for (ll x : ans) {
            tmp.eb(x);
            cur ^= x;
            if ((cur & (1ll << i)) == 0 && it != bit[i].end()) {
                cur ^= *it;
                tmp.eb(*it);
                ++it;
            }        }
        if (it != bit[i].end()) {
            cout << "No\n";
            return 0;
        }
        ans = tmp;
    }
    cout << "Yes\n";
    cout << ans << '\n';
}