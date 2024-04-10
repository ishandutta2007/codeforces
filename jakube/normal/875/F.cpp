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
        cycle.assign(n, false);
    }

    int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

    void Union(int x, int y)
    {
        int xRoot = Find(x);
        int yRoot = Find(y);

        if (rank[xRoot] < rank[yRoot]) {
            p[xRoot] = yRoot;
            if (xRoot == yRoot)
                cycle[yRoot] = true;
            else
                cycle[yRoot] = cycle[xRoot] || cycle[yRoot];
        } else if (rank[xRoot] > rank[yRoot]) {
            p[yRoot] = xRoot;
            if (xRoot == yRoot)
                cycle[xRoot] = true;
            else
                cycle[xRoot] = cycle[xRoot] || cycle[yRoot];
        } else {
            p[yRoot] = xRoot;
            rank[xRoot]++;
            if (xRoot == yRoot)
                cycle[xRoot] = true;
            else
                cycle[xRoot] = cycle[xRoot] || cycle[yRoot];
        }
    }

    bool allowed(int x, int y)
    {
        int X = Find(x);
        int Y = Find(y);
        if (X == Y) {
            return !cycle[X];
        }
        return !(cycle[X] && cycle[Y]);
    }

private:
    std::vector<int> p, rank;
    std::vector<bool> cycle;
};

struct Edge {
    int u, v, w;
    bool used = false;
};

int MST_Kruskal(std::vector<Edge> &edges, int nodes)
{
    sort(edges.begin(), edges.end(),
         [](Edge const &e, Edge const &f) { return e.w > f.w; });

    UnionFind uf(nodes);
    int cost = 0;
    for (Edge &e : edges) {
        if (uf.allowed(e.u, e.v)) {
            uf.Union(e.u, e.v);
            e.used = true;
            cost += e.w;
        }
    }
    return cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        auto &e = edges[i];
        cin >> e.u >> e.v >> e.w;
        e.u--;
        e.v--;
    }

    cout << MST_Kruskal(edges, n) << endl;
}