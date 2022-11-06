#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
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

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 3e5 + 10;
vector<int> s[N];
vector<int> e[N];
int col[N];

void dfs(int u, int p) {
    set<int> used;
    for (int tp : s[u])
        used.insert(col[tp]);
    int ix = 0;
    for (int tp : s[u])
        if (col[tp] == -1) {
            while (used.count(ix)) ++ix;
            col[tp] = ix;
            ++ix;
        }
    for (int v : e[u])
        if (v != p) dfs(v, u);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    forn(i, 0, n) {
        int sz;
        scanf("%d", &sz);
        s[i].resize(sz);
        forn(j, 0, sz)  {
            scanf("%d", &s[i][j]);
            --s[i][j];
        }
    }
    forn(i, 1, n) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u, --v;
        e[u].eb(v);
        e[v].eb(u);
    }
    forn(i, 0, m) col[i] = -1;
    int mx = -1, u = -1;
    forn(i, 0, n) if ((int)s[i].size() > mx) {
        mx = s[i].size();
        u = i;
    }
    forn(i, 0, mx)
        col[s[u][i]] = i;
    for (int v : e[u])
        dfs(v, u);
    if (mx == 0) mx = 1;
    forn(i, 0, m) if (col[i] == -1) col[i] = 0;
    printf("%d\n", mx);
    forn(i, 0, m) printf("%d ", 1 + col[i]);
}