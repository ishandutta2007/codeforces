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

const int N = 1111;
vector<int> e[N];
char tbl[N][N];

vector<int> bfs(int s, int n) {
    vector<int> dst(n, INF);
    queue<pair<int, int>> q;
    q.emplace(s, 0);
    while(!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        if (dst[u] != INF) continue;
        dst[u] = d;
        for (int v : e[u])
            if (dst[v] == INF)
                q.emplace(v, d + 1);
    }
    return dst;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s, --t;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].eb(v);
        e[v].eb(u);
        tbl[u][v] = tbl[v][u] = 1;
    }
    vector<int> ds = bfs(s, n);
    vector<int> dt = bfs(t, n);
    int ans = 0;
    forn(i, 0, n)
        forn(j, 0, i)
            if (!tbl[i][j] && min(ds[i] + 1 + dt[j], ds[j] + 1 + dt[i]) >= ds[t])
                ++ans;
    cout << ans << '\n';
}