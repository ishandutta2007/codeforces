#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

struct rand_int_
{
    using lint = long long;
    mt19937 mt;
    rand_int_() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    lint operator()(lint x) { return this->operator()(0, x); } // [0, x)
    lint operator()(lint l, lint r)
    {
        uniform_int_distribution<lint> d(l, r - 1);
        return d(mt);
    }
} rnd;

vector<int> dict, dict_inv;

pint query(vector<int> vec)
{
    cout << "? " << vec.size();
    for (auto x : vec) cout << ' ' << dict.at(x) + 1;
    cout << endl;
    int x, d;
    cin >> x >> d;
    if (x < 0 and d < 0) exit(8);
    return pint(dict_inv.at(x - 1), d);
}

void answer(int a, int b)
{
    cout << "! " << dict.at(a) + 1 << ' ' << dict.at(b) + 1 << endl;
    string str;
    cin >> str;
    if (str != "Correct") exit(8);
}

// lowest common ancestor (LCA) class for undirected weighted tree
// 
// <https://yukicoder.me/submissions/392383>
struct UndirectedWeightedTree
{
    using T = long long int;   // Arbitrary data structure (operator+, operator- must be defined)
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

void solve()
{
    int N;
    cin >> N;
    dict.resize(N), dict_inv.resize(N);
    REP(i, N) dict[i] = i;
    // random_shuffle(dict.begin(), dict.end(), rnd);
    REP(i, N) dict_inv[dict[i]] = i;

    UndirectedWeightedTree tree(N);
    vector<vector<int>> dij(N);
    REP(_, N - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree.add_edge(u, v, 1);
    }
    REP(i, N)
    {
        tree.fix_root(i);
        dij[i] = tree.depth;
    }

    vector<int> vecall(N);
    REP(i, N) vecall[i] = i;
    auto [r, len] = query(vecall);


    tree.doubling_precalc();

    int S = r, T = r;
    while (dij[S][T] < len)
    {
        int X = (len - dij[S][T] + 1) / 2;
        vector<int> cand;
        REP(i, N)
        {
            if ((dij[S][i] == X or dij[T][i] == X))
            {
                if (dij[S][i] + dij[T][i] > dij[S][T]) cand.emplace_back(i);
            }
        }
        auto pa = query(cand);
        // assert(pa.second == len);
        int V = pa.first;
        if (dij[S][V] < dij[T][V]) S = V;
        else T = V;
    }
    answer(S, T);
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}