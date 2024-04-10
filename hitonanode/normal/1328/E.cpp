#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


// lowest common ancestor (LCA) class for undirected weighted tree
// 
// <https://yukicoder.me/submissions/392383>
struct UndirectedWeightedTree
{
    using T = int;   // Arbitrary data structure (operator+, operator- must be defined)
    int INVALID = -1;
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

    UndirectedWeightedTree() = default;
    UndirectedWeightedTree(int N) : V(N), E(0), adj(N)
    {
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
        if (depth[x] < k) return INVALID;
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

int main()
{
    int N, M;
    cin >> N >> M;
    UndirectedWeightedTree tree(N + 1);
    vector<set<int>> adj(N + 1);
    REP(_, N - 1) {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u, v, 1);
        adj[u].insert(v);
        adj[v].insert(u);
    }
    tree.add_edge(0, 1, 1);
    adj[0].insert(1);
    adj[1].insert(0);

    tree.fix_root(0);
    tree.doubling_precalc();
    while (M--) {
        int K;
        cin >> K;
        vector<pint> V(K);
        REP(i, K) {
            cin >> V[i].second;
            V[i].first = tree.depth[V[i].second];
        }
        sort(V.rbegin(), V.rend());
        int now = V[0].second;
        int dnow = V[0].first;
        bool flg = true;
        for (auto p : V) if (p.second != now) {
            int nxt = p.second, dnxt = p.first;
            now = tree.kth_parent(now, dnow - dnxt + 1);
            if (now >= 0 and adj[now].count(nxt)) {
                dnow = tree.depth[now];
                continue;
            }
            else {
                flg = false;
                break;
            }
        }
        cout << (flg ? "YES" : "NO") << "\n";
    }
}