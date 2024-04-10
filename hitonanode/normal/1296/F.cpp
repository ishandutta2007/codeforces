#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }

struct custom_hash
{
    // <https://codeforces.com/blog/entry/62393>
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(pint x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first * (1LL << 32) + x.second + FIXED_RANDOM);
    }
};

struct UndirectedWeightedTree
{
    using T = long long int;   // Arbitrary data structure (operator+, operator- must be defined)
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
};

int main()
{
    int N;
    cin >> N;
    UndirectedWeightedTree tree(N);
    unordered_map<pint, int, custom_hash> eid;
    REP(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree.add_edge(u, v, 1);
        eid[{u, v}] = eid[{v, u}] = i;
    }
    tree.fix_root(0);
    tree.doubling_precalc();
    int M;
    cin >> M;
    vector<pint> q(M);
    vector<int> R(M);
    vector<int> V(M);
    vector<int> ret(N - 1, 1);
    REP(i, M) {
        int u, v;
        cin >> u >> v >> V[i];
        u--, v--;
        q[i] = make_pair(u, v);
        R[i] = tree.lowest_common_ancestor(u, v);
        REP(_, 2) {
            while (u != R[i]) {
                int t = tree.par[u];
                mmax(ret[eid[{u, t}]], V[i]);
                u = t;
            }
            swap(u, v);
        }
    }
    REP(i, M) {
        int mini = 1e9;
        REP(_, 2) {
            int u = q[i].first;
            while (u != R[i]) {
                int t = tree.par[u];
                mmin(mini, ret[eid[{u, t}]]);
                u = t;
            }
            swap(q[i].first, q[i].second);
        }
        if (mini != V[i]) {
            puts("-1");
            return 0;
        }
    }
    for (auto x : ret) printf("%d ", x);
    puts("");
}