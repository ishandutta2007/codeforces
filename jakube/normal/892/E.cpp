#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, cost;
};

vector<vector<int>> adj;
vector<bool> b;

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

bool dfs(int v, int p = -1)
{
    b[v] = true;
    for (auto u : adj[v]) {
        if (u != p) {
            if (b[u])
                return false;
            if (!dfs(u, v))
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    vector<vector<Edge>> edges_by_cost(500'001);
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--, v--;
        edges.push_back({u, v, cost});
        edges_by_cost[cost].push_back({u, v, cost});
    }

    int q;
    cin >> q;
    vector<bool> queries(q, true);
    vector<map<int, vector<int>>> ma(500'001);
    vector<vector<int>> qs(q);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            ma[edges[y - 1].cost][i].push_back(y - 1);
            qs[i].push_back(y - 1);
        }
    }

    UnionFind uf(n);
    adj.resize(n);
    b.assign(n, false);
    for (int weight = 0; weight <= 500'000; weight++) {
        for (auto& M : ma[weight]) {
            // pass
            vector<int> s;
            for (auto e : M.second) {
                int x = uf.Find(edges[e].u);
                int y = uf.Find(edges[e].v);
                adj[x].push_back(y);
                adj[y].push_back(x);
                s.push_back(x);
                s.push_back(y);
            }

            for (auto v : s) {
                if (!b[v]) {
                    if (!dfs(v)) {
                        queries[M.first] = false;
                        break;
                    }
                }
            }

            for (auto e : s) {
                adj[e].clear();
                b[e] = false;
            }
        }

        for (auto e : edges_by_cost[weight]) {
            uf.Union(e.u, e.v);
        }
    }
    for (auto x : queries)
        if (x)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
}