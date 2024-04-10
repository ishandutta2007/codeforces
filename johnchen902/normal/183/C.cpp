#include <cstdio>
#include <vector>
#include <numeric>

struct Edge {
    int u, v, w;
    // color[v] = color[u] + w
    // w in {1, -1}
};

void dfs(int i, const std::vector<Edge> *adj,
         int *color, char *vis, int *ans) {
    vis[i] = true;
    for (Edge e : adj[i]) {
        if (vis[e.v]) {
            // color[e.v] === color[i] + e.w
            *ans = std::gcd(*ans, color[e.v] - (color[i] + e.w));
        } else {
            color[e.v] = color[i] + e.w;
            dfs(e.v, adj, color, vis, ans);
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    std::vector<std::vector<Edge>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        adj[u].push_back(Edge{u, v, 1});
        adj[v].push_back(Edge{v, u, -1});
    }

    int ans = 0;
    std::vector<int> color(n);
    std::vector<char> vis(n);
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i, adj.data(), color.data(), vis.data(), &ans);

    if (ans == 0)
        ans = n;

    printf("%d\n", ans);
}