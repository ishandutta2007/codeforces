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
#define dbg(x) (x)
#define dbgif(cond, x) 0
#endif

// Weighted UnionFind
template <class S> struct WeightedUnionFind {
    std::vector<int> par, sz;
    std::vector<S> pot;
    WeightedUnionFind(int N = 0) : par(N), sz(N, 1), pot(N) {
        std::iota(par.begin(), par.end(), 0);
    }
    int find(int x) {
        if (par[x] != x) {
            int r = find(par[x]);
            pot[x] = pot[x] + pot[par[x]], par[x] = r;
        }
        return par[x];
    }
    bool unite(int s, int t, S rel_diff) {
        // Relate s and t by f[t] = f[s] + rel_diff
        // Return false iff contradiction happens.
        rel_diff = rel_diff + weight(s) + (-weight(t));
        if ((s = find(s)) == (t = find(t))) return rel_diff == 0;
        if (sz[s] < sz[t]) std::swap(s, t), rel_diff = -rel_diff;
        par[t] = s, sz[s] += sz[t], pot[t] = rel_diff;
        return true;
    }
    S weight(int x) { return find(x), pot[x]; }
    S diff(int s, int t) { return weight(t) + (-weight(s)); } // return f[t] - f[s]
    int count(int x) { return sz[find(x)]; }
    bool same(int s, int t) { return find(s) == find(t); }
};

// Nimber (64 bit)
// Reference:
// - https://en.wikipedia.org/wiki/Nimber
// - https://kyopro-friends.hatenablog.com/entry/2020/04/07/195850
// - https://judge.yosupo.jp/submission/4542 (implementation idea)
struct Nimber {
    using ull = unsigned long long;
    ull v;
    const static std::array<std::array<unsigned, 256>, 256> small_table;
    const static std::array<std::array<std::array<ull, 256>, 8>, 8> precalc;

    explicit operator bool() const { return v != 0; }
    Nimber(ull val = 0) : v(val) {}
    Nimber operator+(const Nimber &x) const { return Nimber(v ^ x.v); }
    Nimber operator-(const Nimber &x) const { return Nimber(v ^ x.v); }
    Nimber operator-() const { return *this; }
    Nimber &operator+=(const Nimber &x) { return *this = *this + x; }
    Nimber &operator-=(const Nimber &x) { return *this = *this + x; }
    template <class IStream> friend IStream &operator>>(IStream &is, Nimber &x) {
        ull v;
        return is >> v, x = Nimber(v), is;
    }
    template <class OStream> friend OStream &operator<<(OStream &os, const Nimber &x) {
        return os << x.v;
    }
    bool operator==(const Nimber &x) const { return v == x.v; }
    bool operator!=(const Nimber &x) const { return v != x.v; }
    bool operator<(const Nimber &x) const { return v < x.v; }

    static ull _rec(ull x, ull y) {
        if (x == 0 or y == 0) return 0;
        if (x < y) x ^= y, y ^= x, x ^= y; // Make x >= y
        if (y == 1) return x;
        for (int shift = 64 / 2;; shift >>= 1) {
            ull mask = (1ULL << shift) - 1;
            if (y >> shift) {
                ull v00 = _rec(x & mask, y & mask);
                ull v01 = _rec(x & mask, y >> shift);
                ull v10 = _rec(x >> shift, y & mask);
                ull v11 = _rec(x >> shift, y >> shift);
                return v00 ^ ((v01 ^ v10 ^ v11) << shift) ^ _rec(v11, 1ULL << (shift - 1));
            } else if (x >> shift) {
                return (_rec(x >> shift, y) << shift) ^ _rec(x & mask, y);
            }
        }
    }
    Nimber operator*(const Nimber &x) const {
        ull ret = 0;
        for (int d = 0; d < 8; ++d) {
            for (int e = 0; e < 8; ++e) {
                ret ^= precalc[d][e][small_table[(v >> (d * 8)) & 255][(x.v >> (e * 8)) & 255]];
            }
        }
        return Nimber(ret);
    }
    Nimber &operator*=(const Nimber &x) { return *this = *this * x; }
};

const std::array<std::array<unsigned, 256>, 256> Nimber::small_table = []() {
    std::array<std::array<unsigned, 256>, 256> ret;
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) ret[i][j] = _rec(i, j);
    }
    return ret;
}();
const std::array<std::array<std::array<unsigned long long, 256>, 8>, 8> Nimber::precalc = []() {
    std::array<std::array<std::array<unsigned long long, 256>, 8>, 8> ret;
    for (int d = 0; d < 8; ++d) {
        for (int e = 0; e < 8; ++e) {
            ull p = _rec(1ULL << (8 * d), 1ULL << (8 * e));
            for (int i = 0; i < 256; ++i) ret[d][e][i] = _rec(p, i);
        }
    }
    return ret;
}();

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


void solve() {
    int N, M;
    cin >> N >> M;
    UndirectedWeightedTree<int> lca(N);
    vector<vector<pint>> to(N);
    WeightedUnionFind<Nimber> uf(N);
    REP(i, N - 1) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        to[a].emplace_back(b, w);
        to[b].emplace_back(a, w);
        lca.add_edge(a, b, 1);
        if (w >= 0) uf.unite(a, b, w);
    }
    lca.fix_root(0);

    vector<tuple<int, int, int>> query;
    vector<vector<int>> v2q(N);
    REP(q, M) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        query.emplace_back(a, b, w);
        v2q[lca.lowest_common_ancestor(a, b)].emplace_back(q);
    }

    vector<tuple<int, int, int>> ret;
    bool bad = false;
    auto rec = [&](auto &&self, int now, int prv) -> void {
        for (auto [nxt, w] : to[now]) {
            if (nxt == prv) continue;
            self(self, nxt, now);
        }
        for (auto q : v2q[now]) {
            auto [a, b, parity] = query[q];
            if (uf.same(a, b)) {
                auto d = __builtin_parityll(uf.diff(a, b).v);
                if (d != parity) {
                    bad = true;
                    break;
                }
            } else {
                uf.unite(a, b, parity);
            }
        }
    };
    rec(rec, 0, -1);

    if (bad) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        REP(i, N) {
            for (auto [j, w] : to[i]) {
                if (i < j) {
                    cout << i + 1 << ' ' << j + 1 << ' ' << uf.diff(i, j) << '\n';
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}