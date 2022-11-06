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

const int N = 1e5 + 10;

vector<int> e[2 * N];
char used[2 * N];
ll pow2[2 * N];

int vers, eds;

void dfs(int u) {
    if (used[u]) return;
    used[u] = 1;
    ++vers;
    eds += (int)e[u].size();
    for (int v : e[u]) dfs(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    pow2[0] = 1;
    forn(i, 1, 2 * N)
        pow2[i] = 2 * pow2[i - 1] % MOD;
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    forn(i, 0, n) cin >> x[i] >> y[i];
    map<int, int> xs, ys;
    forn(i, 0, n) xs[x[i]] = 0;
    forn(i, 0, n) ys[y[i]] = 0;
    int cnt = 0;
    for (auto& p : xs)
        p.sn = cnt++;
    cnt = 0;
    for (auto& p : ys)
        p.sn = cnt++;
    forn(i, 0, n) {
        int u = xs[x[i]];
        int v = ys[y[i]] + (int)xs.size();
        e[u].eb(v);
        e[v].eb(u);
    }
    int sz = (int)xs.size() + (int)y.size();
    ll ans = 1;
    forn(i, 0, sz) if (!used[i]) {
        vers = 0, eds = 0;
        dfs(i);
        eds /= 2;
        if (eds == vers - 1)
            ans *= pow2[vers] - 1;
        else
            ans *= pow2[vers];
        ans %= MOD;
    }
    cout << ans << '\n';
}