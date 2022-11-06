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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, m;
    cin >> n >> m;
    int cl, ce, v;
    cin >> cl >> ce >> v;
    vector<int> l(cl), e(ce);
    cin >> l >> e;
    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 > y2) {
            swap(y1, y2);
            swap(x1, x2);
        }
        if (x1 == x2) {
            cout << abs(y1 - y2) << '\n';
            continue;
        }
        auto cost = [&] (int pos, int vel) {
            return abs(y1 - pos) + abs(y2 - pos) + (abs(x1 - x2) + vel - 1) / vel;
        };
        int ans = INF;
        auto it = lower_bound(all(l), y1);
        if (it != l.end())
            setmin(ans, cost(*it, 1));
        if (it != l.begin()) {
            --it;
            setmin(ans, cost(*it, 1));
        }
        it = lower_bound(all(e), y1);
        if (it != e.end())
            setmin(ans, cost(*it, v));
        if (it != e.begin()) {
            --it;
            setmin(ans, cost(*it, v));
        }
        cout << ans << '\n';
    }
}