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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    if (s1 > s2) swap(s1, s2);
    vector<int> x(n + 1);
    x[0] = s2;
    forn(i, 0, n) cin >> x[i + 1];
    int l = s2 - s1 - 1, r = 1e9 + 10;
    while (l < r - 1) {
        int m = (l + r) / 2;
        set<int> pt;
        pt.insert(s1);
        fore(i, 1, n) {
            if (pt.empty()) break;
            while (!pt.empty() && *pt.begin() < x[i] - m)
                pt.erase(pt.begin());
            while (!pt.empty() && *pt.rbegin() > x[i] + m) {
                auto it = pt.end();
                --it;
                pt.erase(it);
            }
            if (abs(x[i] - x[i - 1]) <= m)
                pt.insert(x[i - 1]);
        }
        if (pt.empty())
            l = m;
        else
            r = m;
    }
    cout << r << '\n';
}