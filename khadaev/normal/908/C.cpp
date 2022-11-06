#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

ld solve(ld x1, ld x2, ld y2, ld dst) {
    ld dx = abs(x1 - x2);
    if (dst + eps < dx) return -42.;
    ld dy = sqrt(dst * dst - dx * dx);
    return y2 + dy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, r;
    cin >> n >> r;
    vector<int> x(n);
    forn(i, 0, n) cin >> x[i];
    vector<ld> ans(n);
    forn(i, 0, n) {
        ans[i] = r;
        forn(j, 0, i) setmax(ans[i], solve(x[i], x[j], ans[j], 2 * r));
    }
    cout << fixed << setprecision(10);
    forn(i, 0, n) cout << ans[i] << ' ';
}