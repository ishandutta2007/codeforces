#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1005;

int n, m;
bool adj[mxn][mxn];
bool vis[mxn];
int fa[mxn], dis[mxn];

std::pair <int, int> dfs(int u, int p, int d) {
    dis[u] = d;
    vis[u] = true;
    std::pair <int, int> ans = {d, u};
    rep(v, n) if (adj[u][v] && v != p) {
        fa[v] = u;
        ans = std::max(ans, dfs(v, u, d + 1));
    }
    return ans;
}

std::vector <std::pair <int, int> > edges;

inline void add_edge(int u, int v) {
    edges.push_back({u, v});
    adj[u][v] = adj[v][u] = true;
}

int main() {
    scanf("%d %d", &n, &m);
    rep(i, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        -- u, -- v;
        adj[u][v] = adj[v][u] = true;
    }
    std::vector <std::pair <int, int> > vec;
    rep(u, n) if (!vis[u]) {
        int x = dfs(u, -1, 0).second;
        int y = dfs(x, -1, 0).second;
        int d = dis[y];
        int s = y;
        rep(tc, d / 2) s = fa[s];
        vec.push_back(std::make_pair(d, s));
    }
    std::sort(vec.rbegin(), vec.rend());
    for (int i = 1; i < (int) vec.size(); ++ i)
        add_edge(vec[i].second, vec[0].second);
    int x = dfs(0, -1, 0).second;
    int y = dfs(x, -1, 0).second;
    printf("%d\n", dis[y]);
    rep(i, edges.size()) printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
    return 0;
}