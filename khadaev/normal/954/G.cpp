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
    int n, d;
    cin >> n >> d;
    ll k;
    cin >> k;
    vector<ll> in(n);
    cin >> in;
    ll l = 0, r = ll(2e18);
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        vector<ll> a = in;
        ll sum = 0, add = 0;
        forn(i, 0, min(n, d + 1))
            sum += a[i];
        forn(i, 0, n) {
            if (sum < m) {
                int ix = min(n - 1, i + d);
                a[ix] += m - sum;
                add += m - sum;
                sum = m;
            }
            if (add > k)
                break;
            if (i - d >= 0)
                sum -= a[i - d];
            if (i + d + 1 < n)
                sum += a[i + d + 1];
        }
        //cerr << m << ' ' << add << '\n';
        if (add <= k)
            l = m;
        else
            r = m;
    }
    cout << l << '\n';
}