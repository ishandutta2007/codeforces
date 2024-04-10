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

vector<vector<int>> to;
queue<int> q;
vector<int> D;
void bfs(int now) {
    for (auto nxt : to[now]) if (D[nxt] > D[now] + 1) {
        D[nxt] = D[now] + 1;
        q.push(nxt);
    }
}

struct SizeAwareUnionFind
{
    vector<int> par, cou;
    SizeAwareUnionFind(int N) : par(N), cou(N) { REP(i, N) par[i] = i, cou[i] = 1; }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    void unite(int x, int y) {
        x = find(x), y = find(y); if (x == y) return;
        if (cou[x] < cou[y]) swap(x, y); 
        par[y] = x, cou[x] += cou[y];
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};

int main()
{
    int N, K, R, HK;
    cin >> N >> K >> R;
    HK = (K + 1) / 2;
    UndirectedWeightedTree tree(N);
    to.resize(N);
    REP(_, N - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        tree.add_edge(x, y, 1);
        to[x].push_back(y);
        to[y].push_back(x);
    }
    tree.fix_root(0);
    tree.doubling_precalc();
    D.assign(N, 1e9);
    vector<int> conn(N);
    while (R--) {
        int r;
        cin >> r;
        D[r - 1] = 0;
        q.push(r - 1);
        conn[r - 1] = 1;
    }
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        bfs(n);
    }
    // dbg(D);
    SizeAwareUnionFind uf(N);
    REP(s, N) for (auto t : to[s]) {
        if (D[s] + D[t] + 1 <= K) uf.unite(s, t), conn[s] = conn[t] = 1;
    }
    int V;
    cin >> V;
    while (V--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        bool f = false;
        int l = tree.path_length(a, b);
        // dbg((vector<int>{a, b, l}));
        if (l <= K or uf.same(a, b)) f = true;
        else
        {
            int r = tree.lowest_common_ancestor(a, b);
            // REP(_, 2)
            // {
            //     if (r == a) {
            //         int ac = tree.kth_parent(b, l - HK);
            //         int bc = tree.kth_parent(b, HK);
            //         f = f or (uf.same(ac, bc) and conn[ac]);
            //     }
            //     swap(a, b);
            // }
            int ar = tree.path_length(a, r);
            int br = l - ar;
            int ac = (ar >= HK ? tree.kth_parent(a, HK) : tree.kth_parent(b, l - HK));
            int bc = (br >= HK ? tree.kth_parent(b, HK) : tree.kth_parent(a, l - HK));
            f = f or (uf.same(ac, bc) and conn[ac]);
        }
        if (f) puts("YES");
        else puts("NO");
    }
}