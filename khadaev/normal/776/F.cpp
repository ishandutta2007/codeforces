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

const int N = 1e5 + 10;
vector<int> plgn[N];
vector<int> id[N];

vector<int> order[N];
int sorted[N];

vector<int> e[N];
int ix = -1, n;

bool cmp (int i, int j) {
    if (order[i].size() == 2 * n) return i != j;
    if (order[j].size() == 2 * n) return false;
    return order[i] > order[j];
}

void go(int i, int j, int ID) {
    if (id[i][j] != -1) return;
    id[i][j] = ID;
    int to = plgn[i][j];
    int pos = lower_bound(all(plgn[to]), i) - plgn[to].begin();
    ++pos;
    if (pos == plgn[to].size()) pos = 0;
    go(to, pos, ID);
}

int level [N];

int lst[N];
int tmp = 0, sz;

void dfs1 (int v) {
    if (level[v] != -1 || v == 0 || lst[v] == tmp) return;
    lst[v] = tmp;
    ++sz;
    for (int u : e[v]) dfs1(u);
}

int dfs2 (int v, int size, int& center, int p = -1) {
    int sum = 1;
    for (int x : e [v])
        if (level [x] == -1 && x != p)
            sum += dfs2 (x, size, center, v) ;
    if (center == -1 && 2 * sum >= size)
        center = v;
    return sum ;
}

void build (int v, int depth) {
    ++tmp;
    sz = 0;
    dfs1(v);
    int center = -1 , size = sz;
    dfs2 (v, size , center );
    level [ center ] = depth ;
    for (int x : e [center])
        if (level [x] == -1) {
            build (x, depth + 1) ;
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> n >> m;
    forn(i, 0, n - 1) plgn[i].eb(i + 1);
    plgn[n - 1].eb(0);
    forn(i, 1, n) plgn[i].eb(i - 1);
    plgn[0].eb(n - 1);
    forn(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        plgn[u].eb(v);
        plgn[v].eb(u);
    }
    forn(i, 0, n) sort(all(plgn[i]));
    forn(i, 0, n) id[i].resize(plgn[i].size(), -1);
    forn(i, 0, n) forn(j, 0, id[i].size()) if (id[i][j] == -1) go(i, j, ++ix);
    ++ix;
    forn(i, 0, n) forn(j, 0, id[i].size()) {
        order[id[i][j]].eb(-i);
        order[id[i][j]].eb(-plgn[i][j]);
    }
    forn(i, 0, ix) sort(all(order[i]));
    /*forn(i, 0, ix) {
        cout << i << ": ";
        for (int j : order[i]) cout << j << ' ';
        cout << '\n';
    }*/
    forn(i, 0, ix) sorted[i] = i;
    sort(sorted, sorted + ix, cmp);
    //forn(i, 0, ix) cout << sorted[i] << ' ';
    //cout << '\n';
    vector<int> num(ix);
    forn(i, 0, ix) num[sorted[i]] = i;
    map<pair<int, int>, int> graph;
    forn(i, 0, n) forn(j, 0, id[i].size()) graph[{i, plgn[i][j]}] = id[i][j];
    for (auto p : graph) {
        int i = p.fs.fs, j = p.fs.sn, u = p.sn;
        int v = graph[{j, i}];
        e[num[u]].eb(num[v]);
    }
    forn(i, 1, ix) {
        sort(all(e[i]));
        vector<int> ne;
        forn(j, 0, e[i].size()) {
            if (e[i][j] == 0) continue;
            if (j == 0 || e[i][j] != e[i][j - 1]) ne.eb(e[i][j]);
        }
        e[i] = ne;
    }
    /*forn(i, 0, ix) {
        cout << i << ": ";
        for (int j : e[i]) cout << j << ' ';
        cout << '\n';
    }*/
    forn(i, 0, ix) level[i] = -1;
    build(1, 0);
    forn(i, 1, ix) cout << 1 + level[i] << '\n';
}