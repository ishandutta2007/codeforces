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

struct Edge {
    int a, b, w;

    Edge () {}

    bool operator< (const Edge& ot) const {
        return w > ot.w;
    }
};

const int N = 2e5 + 10;
int p[N];
char bad[N];

ll ans = 0;

int get(int u) {
    if (u == p[u]) return u;
    return p[u] = get(p[u]);
}

void try_unite(Edge x) {
    int u = get(x.a), v = get(x.b);
    if (u == v) {
        if (bad[u]) return;
        bad[u] = 1;
        ans += x.w;
        return;
    }
    if (bad[u] && bad[v]) return;
    p[u] = v;
    ans += x.w;
    bad[v] = bad[u] || bad[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, m;
    cin >> n >> m;
    forn(i, 0, n) p[i] = i;
    vector<Edge> e(m);
    for (Edge& x : e) {
        cin >> x.a >> x.b >> x.w;
        --x.a, --x.b;
    }
    sort(all(e));
    for (Edge x : e)
        try_unite(x);
    cout << ans << '\n';
}