#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

struct UnionFind
{
    std::vector<int> par, rank;
    UnionFind(int N = 0): par(N), rank(N) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) par[x] = y;
        else par[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
};
struct UndirectedWeightedTree
{
    using T = long long int; // Arbitrary data structure (operator+, operator- must be defined)
    const int INVALID = -1;
    int V, lgV;
    int E;
    int root;
    vector<vector<pair<int, int>>> adj; // (nxt_vertex, edge_id)
    // vector<pint> edge;  // edges[edge_id] = (vertex_id, vertex_id)
    vector<T> weight;     // w[edge_id]
    vector<int> par;      // parent_vertex_id[vertex_id]
    vector<int> depth;    // depth_from_root[vertex_id]
    vector<T> acc_weight; // w_sum_from_root[vertex_id]

    void _fix_root_dfs(int now, int prv, int prv_edge_id)
    {
        par[now] = prv;
        if (prv_edge_id != INVALID)
            acc_weight[now] = acc_weight[prv] + weight[prv_edge_id];
        for (auto nxt : adj[now])
            if (nxt.first != prv)
            {
                depth[nxt.first] = depth[now] + 1;
                _fix_root_dfs(nxt.first, now, nxt.second);
            }
    }

public:
    UndirectedWeightedTree(int N = 0) : V(N), E(0), adj(N)
    {
        lgV = 1;
        while (1 << lgV < V)
            lgV++;
    }

    void add_edge(int u, int v, T w)
    {
        adj[u].emplace_back(v, E);
        adj[v].emplace_back(u, E);
        // edge.emplace_back(u, v);
        weight.emplace_back(w);
        E++;
    }

    vector<T> dijkstra_ret;
    void _dijkstra_dfs(int now, int prv) {
        for (auto nxt : adj[now]) if (nxt.first != prv) {
            dijkstra_ret[nxt.first] = dijkstra_ret[now] + weight[nxt.second];
            _dijkstra_dfs(nxt.first, now);
        }
    }
    vector<T> dijkstra(int s)
    {
        dijkstra_ret.assign(V, 0);
        _dijkstra_dfs(s, -1);
        return dijkstra_ret;
    }

    void fix_root(int r)
    {
        root = r;
        par.resize(V);
        depth.assign(V, 0);
        acc_weight.resize(V);
        acc_weight[r] = 0;
        _fix_root_dfs(root, INVALID, INVALID);
    }

    vector<vector<int>> doubling;
    void doubling_precalc()
    {
        doubling.assign(lgV, vector<int>(V));
        doubling[0] = par;
        for (int d = 0; d < lgV - 1; d++)
            for (int i = 0; i < V; i++)
            {
                if (doubling[d][i] == INVALID)
                    doubling[d + 1][i] = INVALID;
                else
                    doubling[d + 1][i] = doubling[d][doubling[d][i]];
            }
    }

    int kth_parent(int x, int k)
    {
        for (int d = 0; d < lgV; d++)
        {
            if (x == INVALID)
                return INVALID;
            if (k & (1 << d))
                x = doubling[d][x];
        }
        return x;
    }

    int lowest_common_ancestor(int u, int v)
    {
        if (depth[u] > depth[v])
            swap(u, v);

        v = kth_parent(v, depth[v] - depth[u]);
        if (u == v)
            return u;
        for (int d = lgV - 1; d >= 0; d--)
        {
            if (doubling[d][u] != doubling[d][v])
                u = doubling[d][u], v = doubling[d][v];
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
    UnionFind uf(N);
    UndirectedWeightedTree tree(N);
    vector<pair<pint, int>> additional_edges;

    REP(_, M)
    {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        if (uf.same(u, v)) additional_edges.emplace_back(pint(u, v), d);
        else {
            tree.add_edge(u, v, d);
            uf.unite(u, v);
        }
    }
    tree.fix_root(0);
    tree.doubling_precalc();

    vector<int> special_vertices;
    for (auto x : additional_edges) special_vertices.push_back(x.first.first), special_vertices.push_back(x.first.second);
    sort(ALL(special_vertices));
    special_vertices.erase(unique(ALL(special_vertices)), special_vertices.end());
    int V = special_vertices.size();
    map<int, int> spvinv;
    for (auto x : special_vertices) {
        int n = spvinv.size();
        spvinv[x] = n;
    }
    vector<vector<lint>> dmat(V, vector<lint>(V, 1e18));
    REP(i, V) dmat[i][i] = 0;

    for (auto e : additional_edges) {
        int u = spvinv[e.first.first];
        int v = spvinv[e.first.second];
        mmin<lint>(dmat[u][v], e.second);
        mmin<lint>(dmat[v][u], e.second);
    }
    REP(i, V) REP(j, V) mmin(dmat[i][j], tree.path_length(special_vertices[i], special_vertices[j]));

    REP(k, V) REP(i, V) REP(j, V) mmin(dmat[i][j], dmat[i][k] + dmat[k][j]);

    vector<vector<lint>> dist2(V);
    REP(i, V) {
        tree.fix_root(special_vertices[i]);
        dist2[i] = tree.acc_weight;
    }
    tree.doubling_precalc();
    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        lint ret = tree.path_length(a, b);
        REP(i, V) REP(j, V) mmin(ret, dist2[i][a] + dmat[i][j] + dist2[j][b]);
        printf("%lld\n", ret);
    }
}