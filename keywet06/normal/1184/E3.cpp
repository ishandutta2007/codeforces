#include <bits/stdc++.h>

using namespace std;

const int C = 30;
const int N = 100005;
const int M = 1000005;

struct edge {
    int u, v, w, i;
    bool operator<(const edge &x) const { return w < x.w; }
};

bool vis[M];

int n, log2n, m;
int fa[N], fa2[N], de[N], nw[N];
int f[N][C], g[N][C];

edge ed[M];

vector<pair<int, int> > e[N];
vector<pair<int, int> > ans;

int getfa(int x) { return (x == fa[x] ? x : fa[x] = getfa(fa[x])); }

int getfa2(int x) { return (x == fa2[x] ? x : fa2[x] = getfa2(fa2[x])); }

void dfs(int u, int fa) {
    f[u][0] = fa;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i].first, w = e[u][i].second;
        if (v == fa) continue;
        de[v] = de[u] + 1;
        g[v][0] = w;
        dfs(v, u);
    }
}

pair<int, int> lca(int u, int v) {
    int res = -0x3f3f3f3f;
    if (de[u] < de[v]) swap(u, v);
    int k = de[u] - de[v];
    for (int i = 0; k; k >>= 1, i++)
        if (k & 1) res = max(g[u][i], res), u = f[u][i];
    if (u == v) return {res, u};
    for (int i = log2n; i >= 0; i--)
        if (f[u][i] != f[v][i])
            res = max(max(g[u][i], g[v][i]), res), u = f[u][i], v = f[v][i];
    return {max(res, max(g[u][0], g[v][0])), f[u][0]};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    log2n = log2(n);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> ed[i].u >> ed[i].v >> ed[i].w;
        ed[i].i = i;
    }
    sort(ed + 1, ed + 1 + m);
    for (int i = 1; i <= m; i++) {
        int u = ed[i].u, v = ed[i].v, w = ed[i].w;
        int uu = getfa(u), vv = getfa(v);
        if (uu != vv) {
            fa[uu] = vv;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
            vis[i] = 1;
        }
    }

    dfs(1, 0);
    for (int j = 1; j <= log2n; j++)
        for (int i = 1; i <= n; i++)
            f[i][j] = f[f[i][j - 1]][j - 1],
            g[i][j] = max(g[i][j - 1], g[f[i][j - 1]][j - 1]);
    for (int i = 1; i <= n; i++) fa2[i] = i, nw[i] = 1000000000;

    for (int i = 1; i <= m; i++) {
        int u = ed[i].u, v = ed[i].v, w = ed[i].w;
        if (!vis[i]) {
            pair<int, int> tmp = lca(u, v);
            ans.push_back({ed[i].i, tmp.first});
            while (de[getfa2(u)] > de[tmp.second]) {
                int uu = getfa2(u);
                nw[uu] = w;
                fa2[uu] = getfa2(f[uu][0]);
            }
            while (de[getfa2(v)] > de[tmp.second]) {
                int vv = getfa2(v);
                nw[vv] = w;
                fa2[vv] = getfa2(f[vv][0]);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!vis[i]) continue;
        int u = ed[i].u, v = ed[i].v;
        if (de[u] < de[v]) swap(u, v);
        ans.push_back({ed[i].i, nw[u]});
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i].second << endl;
    return 0;
}