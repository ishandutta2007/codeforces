#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    UnionFind(int n)
    {
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
        rank.assign(n, 0);
    }

    int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

    void Union(int x, int y)
    {
        int xRoot = Find(x);
        int yRoot = Find(y);

        if (xRoot == yRoot)
            return;

        if (rank[xRoot] < rank[yRoot]) {
            p[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            p[yRoot] = xRoot;
        } else {
            p[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

    bool sameUnion(int x, int y) { return Find(x) == Find(y); }

private:
    std::vector<int> p, rank;
};

struct Edge {
    int u, v, w;
    bool used = false;
};

int largest = 0;
set<int> important;
void dfs(int v, int p, vector<vector<pair<int, int>>> const& adj, int cur_max) {
    if (important.count(v))
        largest = max(cur_max, largest);
    for (auto [u, w] : adj[v]) {
        if (u == p)
            continue;
        dfs(u, v, adj, max(cur_max, w));
    }
}

int MST_Kruskal(std::vector<Edge>& edges, int nodes)
{
    sort(edges.begin(), edges.end(),
         [](Edge const &e, Edge const &f) { return e.w < f.w; });

    UnionFind uf(nodes);
    int cost = 0;
    for (Edge &e : edges) {
        if (!uf.sameUnion(e.u, e.v)) {
            uf.Union(e.u, e.v);
            e.used = true;
            cost += e.w;
        }
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(k);
    for (auto& x : v) {
        cin >> x;
        x--;
    }
    for (auto x : v)
        important.insert(x);

    vector<vector<int>> adj;
    adj.resize(n);
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v, w};
    }

    MST_Kruskal(edges, n);

    vector<vector<pair<int, int>>> adjj(n);
    for (auto e : edges) {
        if (e.used) {
            adjj[e.u].push_back({e.v, e.w});
            adjj[e.v].push_back({e.u, e.w});
        }
    }

    dfs(v[0], -1, adjj, 0);
    
    for (int i = 0; i < k; i++) {
        cout << largest << ' ';
    }
    cout << '\n';
}