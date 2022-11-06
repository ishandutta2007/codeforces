#include <bits/stdc++.h>
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

const int N = 3e5 + 10;

vector<pair<int, int>> e[N];
int d[N], deg[N];
vector<int> ans;

int used1[N], used2[N];
pair<int, int> eds[N];

int dfs1(int u) {
    if (used1[u]) return u;
    used1[u] = 1;
    if (d[u] == -1) return u;
    for (auto v : e[u]) {
        int x = dfs1(v.fs);
        if (d[x] == -1) return x;
    }
    return u;
}

int dfs2(int u) {
    if (used2[u]) return 0;
    int bal = 0;
    used2[u] = 1;
    for (auto p : e[u]) {
        int x = dfs2(p.fs);
        if (x) {
            ++bal;
            ans.eb(p.sn);
        }
    }
    if (d[u] == -1 || bal % 2 == d[u]) return 0;
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    forn(i, 0, n) scanf("%d", &d[i]);
    forn(i, 0, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u, --v;
        e[u].eb(v, i);
        e[v].eb(u, i);
        eds[i] = {u, v};
    }
    forn(i, 0, n) {
        if (used2[i]) continue;
        int v = dfs1(i);
        dfs2(v);
    }
    for (int ix : ans) {
        auto p = eds[ix];
        ++deg[p.fs];
        ++deg[p.sn];
    }
    forn(i, 0, n) {
        if (d[i] == -1) continue;
        if (d[i] != deg[i] % 2) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", (int)ans.size());
    sort(all(ans));
    for (int i : ans) printf("%d ", i + 1);
}