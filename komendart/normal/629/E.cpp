#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int maxn = 1e5 + 5;

int n, m;
vector<int> graph[maxn];
long long sum[maxn];
int sz[maxn];
long long sumall[maxn];
int depth[maxn];
int go[maxn][20];
int tin[maxn], tout[maxn], timer = 0;

void dfs1(int v, int p) {
    depth[v] = (p == -1) ? 0: depth[p] + 1;
    tin[v] = ++timer;
    sum[v] = 0;
    sz[v] = 0;
    for (auto u: graph[v]) {
        if (u != p) {
            dfs1(u, v);
            sum[v] += sum[u];
            sz[v] += sz[u];
        }
    }
    sum[v] += sz[v];
    sz[v]++;
    tout[v] = ++timer;
}

void dfs2(int v, int p) {
    if (p == -1) {
        sumall[v] = sum[v];
    } else {
        sumall[v] = sumall[p] + n - 2 * sz[v];
    }
    for (auto u: graph[v]) {
        if (u != p) {
            dfs2(u, v);
        }
    }
}

void dfs3(int v, int p) {
    if (p == -1) {
        for (int i = 0; i < 20; i++) {
            go[v][i] = 0;
        }
    } else {
        go[v][0] = p;
        for (int i = 1; i < 20; i++) {
            go[v][i] = go[go[v][i - 1]][i - 1];
        }
    }
    for (auto u: graph[v]) {
        if (u != p) {
            dfs3(u, v);
        }
    }
}

inline bool isAncestor(int v, int u) {
    return tin[v] < tin[u] && tout[u] < tout[v];
}

int get_lca(int v, int u) {
    if (isAncestor(v, u)) return v;
    if (isAncestor(u, v)) return u;
    for (int i = 19; i >= 0; i--) {
        int t = go[v][i];
        if (!isAncestor(t, u)) v = t;
    }
    return go[v][0];
}

int get_parent(int v, int h) {
    if (depth[v] == h) return v;
    for (int i = 19; i >= 0; i--) {
        int t = go[v][i];
        if (depth[t] > h) v = t;
    }
    return go[v][0];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs1(0, -1);
    dfs2(0, -1);
    dfs3(0, -1);

    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        v--; u--;
        if (isAncestor(v, u) || isAncestor(u, v)) {
            if (isAncestor(u, v)) swap(v, u);
            int t = get_parent(u, depth[v] + 1);
            double ans = depth[u] - depth[v] + 1;
            ans += sum[u] / (double) sz[u];
            ans += (sumall[v] - sum[t] - sz[t]) / (double) (n - sz[t]);
            printf("%.8f\n", ans);
        } else {
            int lca = get_lca(v, u);
            double ans = depth[v] + depth[u] - 2 * depth[lca] + 1;
            ans += sum[v] / (double) sz[v];
            ans += sum[u] / (double) sz[u];
            printf("%.8f\n", ans);
        }
    }
}