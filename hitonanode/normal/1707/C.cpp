#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#define dbgif(cond, x) ((cond) ? cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl : cerr)
#else
#define dbg(x) 0
#define dbgif(cond, x) 0
#endif

// lowest common ancestor (LCA) for undirected weighted tree
template <typename T> struct UndirectedWeightedTree {
    int INVALID = -1;
    int V, lgV;
    int E;
    int root;
    std::vector<std::vector<std::pair<int, int>>> adj; // (nxt_vertex, edge_id)
    // vector<pint> edge; // edges[edge_id] = (vertex_id, vertex_id)
    std::vector<T> weight;     // w[edge_id]
    std::vector<int> par;      // parent_vertex_id[vertex_id]
    std::vector<int> depth;    // depth_from_root[vertex_id]
    std::vector<T> acc_weight; // w_sum_from_root[vertex_id]

    void _fix_root_dfs(int now, int prv, int prv_edge_id) {
        par[now] = prv;
        if (prv_edge_id != INVALID) acc_weight[now] = acc_weight[prv] + weight[prv_edge_id];
        for (auto nxt : adj[now])
            if (nxt.first != prv) {
                depth[nxt.first] = depth[now] + 1;
                _fix_root_dfs(nxt.first, now, nxt.second);
            }
    }

    UndirectedWeightedTree() = default;
    UndirectedWeightedTree(int N) : V(N), E(0), adj(N) {
        lgV = 1;
        while (1 << lgV < V) lgV++;
    }

    void add_edge(int u, int v, T w) {
        adj[u].emplace_back(v, E);
        adj[v].emplace_back(u, E);
        // edge.emplace_back(u, v);
        weight.emplace_back(w);
        E++;
    }

    std::vector<std::vector<int>> doubling;
    void _doubling_precalc() {
        doubling.assign(lgV, std::vector<int>(V));
        doubling[0] = par;
        for (int d = 0; d < lgV - 1; d++)
            for (int i = 0; i < V; i++) {
                if (doubling[d][i] == INVALID)
                    doubling[d + 1][i] = INVALID;
                else
                    doubling[d + 1][i] = doubling[d][doubling[d][i]];
            }
    }

    void fix_root(int r) {
        root = r;
        par.resize(V);
        depth.resize(V);
        depth[r] = 0;
        acc_weight.resize(V);
        acc_weight[r] = 0;
        _fix_root_dfs(root, INVALID, INVALID);
        _doubling_precalc();
    }

    int kth_parent(int x, int k) {
        if (depth[x] < k) return INVALID;
        for (int d = 0; d < lgV; d++) {
            if (x == INVALID) return INVALID;
            if (k & (1 << d)) x = doubling[d][x];
        }
        return x;
    }

    int lowest_common_ancestor(int u, int v) {
        if (depth[u] > depth[v]) std::swap(u, v);

        v = kth_parent(v, depth[v] - depth[u]);
        if (u == v) return u;
        for (int d = lgV - 1; d >= 0; d--) {
            if (doubling[d][u] != doubling[d][v]) u = doubling[d][u], v = doubling[d][v];
        }
        return par[u];
    }

    T path_length(int u, int v) {
        // Not distance, but the sum of weights
        int r = lowest_common_ancestor(u, v);
        return (acc_weight[u] - acc_weight[r]) + (acc_weight[v] - acc_weight[r]);
    }
};


// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind {
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) { iota(par.begin(), par.end(), 0); }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
    std::vector<std::vector<int>> groups() {
        std::vector<std::vector<int>> ret(par.size());
        for (int i = 0; i < int(par.size()); ++i) ret[find(i)].push_back(i);
        ret.erase(std::remove_if(ret.begin(), ret.end(),
                                 [&](const std::vector<int> &v) { return v.empty(); }),
                  ret.end());
        return ret;
    }
};


int main() {
    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    UndirectedWeightedTree<int> tree(N);
    vector<tuple<int, int, int>> rem_edges;

    vector<vector<pint>> to(N);
    REP(e, M) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if  (uf.unite(a, b)) {
            tree.add_edge(a, b, 1);
            to[a].emplace_back(b, e);
            to[b].emplace_back(a, e);
        } else {
            rem_edges.emplace_back(a, b, e);
        }
    }

    for (auto &v : to) sort(ALL(v));

    auto get_mst_weight = [&](int i, int j) -> int {
        auto itr = lower_bound(ALL(to[i]), pint(j, 0));
        assert(itr->first == j);
        return itr->second;
    };

    const int root = 0;

    vector<int> hi(N, -1), hi2(N, -1);

    REP(i, N) {
        for (auto [_, w] : to[i]) {
            if (w >= hi[i]) {
                hi2[i] = hi[i];
                hi[i] = w;
            } else {
                chmax(hi2[i], w);
            }
        }
    }
    dbg(hi);
    dbg(hi2);
    dbg(to);

    tree.fix_root(root);
    vector<int> cs(N);

    for (auto [a, b, w] : rem_edges) {
        const int l = tree.lowest_common_ancestor(a, b);
        if (l == a or l == b) {
            if (l != b) swap(a, b);
            const int bb = tree.kth_parent(a, tree.depth[a] - tree.depth[b] - 1);

            const int w2 = get_mst_weight(a, tree.par[a]);

            if (w < w2) cs[a]++;

            int chi = hi[a];
            if (hi[a] == w2) chi = hi2[a];

            // if (chi > w) {
            if (true) {
                ++cs[bb];
                --cs[a];
            }

            const int w3 = get_mst_weight(b, bb);
            if (w < w3) ++cs[root], --cs[bb];

            chi = hi[b];
            if (hi[b] == w3) chi = hi2[b];
            // if (chi > w) {
            //     ++cs[bb];
            //     --cs[a];
            // }

        } else {
            REP(_, 2) {
                const int w2 = get_mst_weight(a, tree.par[a]);
                if (w < w2) ++cs[a];

                int chi = hi[a];
                if (hi[a] == w2) chi = hi2[a];

                // if (chi > w) {
                if (true) {
                    ++cs[root];
                    --cs[a];
                    --cs[b];
                }

                swap(a, b);
            }
        }
    }

    auto rec = [&](auto &&self, int now, int prv) -> void {
        for (auto [nxt, w] : to[now]) {
            if (nxt == prv) continue;
            cs[nxt] += cs[now];
            self(self, nxt, now);
        }
    };
    rec(rec, root, -1);
    REP(i, N) cout << (cs[i] ? 0 : 1);
    cout << '\n';
}