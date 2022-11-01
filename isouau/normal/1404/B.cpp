#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector <int> adj[N];
int fa[N], dep[N];
int T, n, a, b, da, db, rt;

void dfs1(int u) {
    for (auto v : adj[u]) {
        if (v == fa[u]) continue;
        fa[v] = u; dep[v] = dep[u] + 1;
        dfs1(v);
    }
}

int lca(int u, int v) {
    while (u != v) {
        if (dep[u] < dep[v]) swap(u, v);
        u = fa[u];
    }
    return u;
}

int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) fa[i] = 0;
        dep[1] = 1; dfs1(1); rt = 1;
        for (int i = 1; i <= n; i++) if (dep[i] > dep[rt]) rt = i;
        for (int i = 1; i <= n; i++) fa[i] = 0;
        dep[rt] = 1; dfs1(rt);
        int maxn = 0;
        for (int i = 1; i <= n; i++) maxn = max(maxn, dep[i]);
        if (da * 2 >= db || da * 2 + 1 >= maxn) {
            printf("Alice\n");
            continue;
        }
        if (dis(a, b) <= da) {
            printf("Alice\n");
            continue;
        }
        printf("Bob\n");
    }
    return 0;
}