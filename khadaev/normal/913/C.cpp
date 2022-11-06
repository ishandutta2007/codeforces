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

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

ll solve(int l, int n, vector<ll>& c) {
    ll ans = 0;
    forn(i, 0, n)
        if (l & (1 << i))
            ans += c[i];
    ans += 2 * c[n - 1] * (l >> n);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, l;
    cin >> n >> l;
    vector<ll> c(n);
    forn(i, 0, n) cin >> c[i];
    ford(i, 1, n) setmin(c[i - 1], c[i]);
    forn(i, 1, n) setmin(c[i], 2 * c[i - 1]);
    ll ans = solve(l, n, c);
    fore(i, 0, n) {
        setmin(ans, solve(((l >> i) + 1) << i, n, c));
    }
    cout << ans << '\n';
}