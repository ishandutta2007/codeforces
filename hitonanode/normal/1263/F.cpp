#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

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
        depth.assign(V, 0);
        acc_weight.resize(V);
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
    T sub_length(int conv, int prop)
    {
        int r = lowest_common_ancestor(conv, prop);
        return path_length(r, prop);
    }
};



int main()
{
    int N, A, B;
    cin >> N >> A;
    vector<int> P(A - 1), X(N + 1);
    cin >> P;
    REP(i, N) cin >> X[i + 1];
    cin >> B;
    vector<int> Q(B - 1), Y(N + 1);
    cin >> Q;
    REP(i, N) cin >> Y[i + 1];

    UndirectedWeightedTree TA(A + 1), TB(B + 1);
    TA.add_edge(0, 1, 0);
    TB.add_edge(0, 1, 0);
    FOR(i, 2, A + 1)
    {
        int par = P.at(i - 2);
        TA.add_edge(par, i, 1);
    }
    FOR(j, 2, B + 1)
    {
        int par = Q.at(j - 2);
        TB.add_edge(par, j, 1);
    }
    TA.fix_root(1);
    TA.doubling_precalc();
    TB.fix_root(1);
    TB.doubling_precalc();
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 1e9));
    dp[0][0] = 0;
    REP(i, N) REP(j, i + 1)
    {
        mmin(dp[j][i + 1], dp[j][i] + TB.sub_length(Y[i], Y[i + 1]));
        mmin(dp[i + 1][i], dp[j][i] + TA.sub_length(X[j], X[i + 1]));

        mmin(dp[i + 1][j], dp[i][j] + TA.sub_length(X[i], X[i + 1]));
        mmin(dp[i][i + 1], dp[i][j] + TB.sub_length(Y[j], Y[i + 1]));
    }
    int ret = 1e9;
    REP(i, N) mmin(ret, dp[i][N]), mmin(ret, dp[N][i]);
    cout << A + B - 2 - ret << endl;
}