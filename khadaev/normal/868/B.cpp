#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
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
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

bool cw(int x, int y, int z) {
    if (x < z) return x < y && y < z;
    else return !cw(z, y, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    if (h == 12) h = 0;
    if (t1 == 12) t1 = 0;
    if (t2 == 12) t2 = 0;

    h = 60 * 60 * h + 60 * m + s;
    m = 12 * 60 * m + 12 * s;
    s = 12 * 60 * s;
    t1 *= 60 * 60;
    t2 *= 60 * 60;
    if (t1 > t2) swap(t1, t2);
    {
        bool ok = true;
        if (cw(t1, h, t2)) ok = false;
        if (cw(t1, m, t2)) ok = false;
        if (cw(t1, s, t2)) ok = false;
        if (ok) {
            cout << "YES\n";
            return 0;
        }
    }
    {
        bool ok = true;
        if (!cw(t1, h, t2)) ok = false;
        if (!cw(t1, m, t2)) ok = false;
        if (!cw(t1, s, t2)) ok = false;
        if (ok) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}