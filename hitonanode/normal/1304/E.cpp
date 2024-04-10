#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }

// lowest common ancestor (LCA) class for undirected weighted tree
// 
// <https://yukicoder.me/submissions/392383>

class UndirectedWeightedTree
{
    using T = int;   // Arbitrary data structure (operator+, operator- must be defined)
    const int INVALID = -1;
    int V, lgV;
    int E;
    int root;
    vector<vector<pair<int, int>>> adj; // (nxt_vertex, edge_id)
    // vector<pint> edge;  // edges[edge_id] = (vertex_id, vertex_id)
    vector<T> weight;  // w[edge_id]
    vector<int> par;  // parent_vertex_id[vertex_id]
    vector<int> depth;  // depth_from_root[vertex_id]
    vector<T> acc_weight;  // w_sum_from_root[vertex_id]

    void _fix_root_dfs(int now, int prv, int prv_edge_id)
    {
        par[now] = prv;
        if (prv_edge_id != INVALID) acc_weight[now] = acc_weight[prv] + weight[prv_edge_id];
        for (auto nxt : adj[now]) if (nxt.first != prv)
        {
            depth[nxt.first] = depth[now] + 1;
            _fix_root_dfs(nxt.first, now, nxt.second);
        }
    }

public:
    UndirectedWeightedTree(int N = 0): V(N), E(0), adj(N) {
        lgV = 1;
        while (1 << lgV < V) lgV++;
    }

    void add_edge(int u, int v, T w)
    {
        adj[u].emplace_back(v, E);
        adj[v].emplace_back(u, E);
        // edge.emplace_back(u, v);
        weight.emplace_back(w);
        E++;
    }

    void fix_root(int r)
    {
        root = r;
        par.resize(V);
        depth.resize(V);
        depth[r] = 0;
        acc_weight.resize(V);
        acc_weight[r] = 0;
        _fix_root_dfs(root, INVALID, INVALID);
    }

    vector<vector<int>> doubling;
    void doubling_precalc()
    {
        doubling.assign(lgV, vector<int>(V));
        doubling[0] = par;
        for (int d = 0; d < lgV - 1; d++) for (int i = 0; i < V; i++)
        {
            if (doubling[d][i] == INVALID) doubling[d + 1][i] = INVALID;
            else doubling[d + 1][i] = doubling[d][doubling[d][i]];
        }
    }

    int kth_parent(int x, int k)
    {
        for (int d = 0; d < lgV; d++)
        {
            if (x == INVALID) return INVALID;
            if (k & (1 << d)) x = doubling[d][x];
        }
        return x;
    }

    int lowest_common_ancestor(int u, int v)
    {
        if (depth[u] > depth[v]) swap(u, v);

        v = kth_parent(v, depth[v] - depth[u]);
        if (u == v) return u;
        for (int d = lgV - 1; d >= 0; d--)
        {
            if (doubling[d][u] != doubling[d][v]) u = doubling[d][u], v = doubling[d][v];
        }
        return par[u];
    }

    T path_length(int u, int v)
    {
        // Not distance, but the sum of weights
        int r = lowest_common_ancestor(u, v);
        return (acc_weight[u] - acc_weight[r]) + (acc_weight[v] - acc_weight[r]);
    }
};

bool check(int d, int k) {
    return k >= d and (k - d) % 2 == 0;
}

int main()
{
    int N;
    cin >> N;
    UndirectedWeightedTree tree(N);
    N--;
    while (N--) {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u - 1, v - 1, 1);
    }
    tree.fix_root(0);
    tree.doubling_precalc();
    int Q;
    cin >> Q;
    while (Q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        x--, y--, a--, b--;
        int d = tree.path_length(a, b);
        bool f = check(d, k);
        if(!f) {
            int l = tree.path_length(x, y);
            REP(_, 2) {
                int d = tree.path_length(a, x) + tree.path_length(b, y);
                mmax(f, check(d + 1, k));
                mmax(f, check(d + l, k));
                mmax(f, check(d + l + 2, k));
                mmax(f, check(d + l * 2 + 1, k));
                swap(x, y);
            }
        }
        if (f) puts("YES");
        else puts("NO");
    }
}