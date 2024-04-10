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

// Preorder Euler Tour
struct PreorderEulerTour {
    int V; // # of vertices of tree
    int root;
    std::vector<std::vector<int>> edges;
    std::vector<int> subtree_begin, subtree_end;
    std::vector<int> vis_order;

    void _build_dfs(int now, int prv) {
        subtree_begin[now] = vis_order.size();
        vis_order.push_back(now);
        for (auto nxt : edges[now])
            if (nxt != prv) _build_dfs(nxt, now);
        subtree_end[now] = vis_order.size();
    }
    PreorderEulerTour() = default;
    PreorderEulerTour(const std::vector<std::vector<int>> &to, int root) : V(to.size()), root(root), edges(to) {
        assert(root >= 0 and root < V);
        subtree_begin.resize(V);
        subtree_end.resize(V);
        _build_dfs(root, -1);
    }
};

// Range Minimum Query for static sequence by sparse table
// Complexity: (N \log N)$ for precalculation, (1)$ per query
template <typename T> struct StaticRMQ {
    inline T func(const T &l, const T &r) const noexcept { return std::min<T>(l, r); }
    int N, lgN;
    T defaultT;
    std::vector<std::vector<T>> data;
    std::vector<int> lgx_table;
    StaticRMQ() = default;
    StaticRMQ(const std::vector<T> &sequence, T defaultT) : N(sequence.size()), defaultT(defaultT) {
        lgx_table.resize(N + 1);
        for (int i = 2; i < N + 1; i++) lgx_table[i] = lgx_table[i >> 1] + 1;
        lgN = lgx_table[N] + 1;
        data.assign(lgN, std::vector<T>(N, defaultT));
        data[0] = sequence;
        for (int d = 1; d < lgN; d++) {
            for (int i = 0; i + (1 << d) <= N; i++) {
                data[d][i] = func(data[d - 1][i], data[d - 1][i + (1 << (d - 1))]);
            }
        }
    }
    T get(int l, int r) const { // [l, r), 0-indexed
        assert(l >= 0 and r <= N);
        if (l >= r) return defaultT;
        int d = lgx_table[r - l];
        return func(data[d][l], data[d][r - (1 << d)]);
    }
};

struct TreeLCA {
    const int N;
    std::vector<std::vector<int>> to;
    bool built;
    TreeLCA(int V = 0) : N(V), to(V), built(false) {}

    void add_edge(int u, int v) {
        assert(0 <= u and u < N);
        assert(0 <= v and v < N);
        assert(u != v);
        to[u].push_back(v);
        to[v].push_back(u);
    }

    using P = std::pair<int, int>;
    std::vector<int> subtree_begin;
    std::vector<P> vis_order;
    std::vector<int> depth;
    void _build_dfs(int now, int prv, int dnow) {
        subtree_begin[now] = vis_order.size();
        vis_order.emplace_back(dnow, now);
        depth[now] = dnow;
        for (auto &&nxt : to[now]) {
            if (nxt != prv) {
                _build_dfs(nxt, now, dnow + 1);
                vis_order.emplace_back(dnow, now);
            }
        }
    }

    StaticRMQ<P> rmq;
    void build(int root = 0) {
        assert(root >= 0 and root < N);
        built = true;
        subtree_begin.resize(N);
        vis_order.reserve(N * 2);
        depth.resize(N);
        _build_dfs(root, -1, 0);
        rmq = {vis_order, P{N, -1}};
    }

    int lca(int u, int v) {
        assert(0 <= u and u < N);
        assert(0 <= v and v < N);
        if (!built) build();

        auto a = subtree_begin[u], b = subtree_begin[v];
        if (a > b) std::swap(a, b);
        return rmq.get(a, b + 1).second;
    };
};


int solve() {
    int N;
    cin >> N;
    vector<vector<int>> g1(N), g2(N);
    FOR(s, 1, N) {
        int t;
        cin >> t;
        t--;
        g1[s].push_back(t), g1[t].push_back(s);
    }
    TreeLCA lca2(N);
    FOR(s, 1, N) {
        int t;
        cin >> t;
        t--;
        g2[s].push_back(t), g2[t].push_back(s);
        lca2.add_edge(s, t);
    }
    PreorderEulerTour tour(g2, 0);
    lca2.build();
    vector<int> exists(N);
    set<int> se;
    se.insert(-1), se.insert(N);
    int ret = 0;

    auto add = [&](int i) {
        se.insert(tour.subtree_begin[i]);
        exists[i] = 1;
    };
    auto rm = [&](int i) {
        se.erase(tour.subtree_begin[i]);
        exists[i] = 0;
    };

    auto rec = [&](auto &&rec, int now, int prv) -> void {
        int le = *prev(se.lower_bound(tour.subtree_begin[now]));
        int erased_i = -1, added_i = -1;
        if (le >= 0 and le < N) {
            int l = tour.vis_order[le];
            if (lca2.lca(l, now) == l) {
                erased_i = l;
                rm(l);
            }
        }
        int re = *prev(se.lower_bound(tour.subtree_begin[now]));

        added_i = now;
        if (re >= 0 and re < N) {
            int r = tour.vis_order[re];
            if (lca2.lca(now, r) == now) {
                added_i = -1;
            }
        }
        if (added_i >= 0) {
            add(now);
        }
        chmax<int>(ret, int(se.size()) - 2);
        for (auto nxt : g1[now]) {
            if (nxt != prv) {
                rec(rec, nxt, now);
            }
        }
        if (added_i >= 0) {
            rm(added_i);
        }
        if (erased_i >= 0) {
            add(erased_i);
        }
    };
    rec(rec, 0, -1);
    return ret;
}

int main() {
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}