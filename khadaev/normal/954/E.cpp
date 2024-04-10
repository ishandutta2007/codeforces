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
    cout << fixed << setprecision(10);
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, t0;
    cin >> n >> t0;
    vector<pair<ll, ll>> t(n);
    forn(i, 0, n) cin >> t[i].sn;
    forn(i, 0, n) cin >> t[i].fs;
    sort(all(t));
    ll sum = 0, amount = 0;
    for (auto [tm, sz] : t)
        sum += tm * sz, amount += sz;
    int l = 0, r = n - 1;
    while (r >= 0 && t0 * amount < sum) {
        auto [tm, sz] = t[r];
        if (t0 * (amount - sz) < (sum - tm * sz)) {
            amount -= sz;
            sum -= tm * sz;
            --r;
        } else {
            ld x = ld(t0 * amount - sum) / ld(t0 - tm);
            cout << amount - x << '\n';
            return 0;
        }
    }
    if (r < 0) {
        cout << 0 << '\n';
        return 0;
    }
    while (l < n && t0 * amount > sum) {
        auto [tm, sz] = t[l];
        if (t0 * (amount - sz) > (sum - tm * sz)) {
            amount -= sz;
            sum -= tm * sz;
            ++l;
        } else {
            ld x = ld(t0 * amount - sum) / ld(t0 - tm);
            cout << amount - x << '\n';
            return 0;
        }
    }
    if (l >= n) {
        cout << 0 << '\n';
    }
    cout << ld(amount) << '\n';
}