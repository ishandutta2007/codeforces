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
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa);

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

// Bipartite matching of undirected bipartite graph (Hopcroft-Karp)
// https://ei1333.github.io/luzhiled/snippets/graph/hopcroft-karp.html
// Comprexity: O((V + E)sqrtV)
// int solve(): enumerate maximum number of matching / return -1 (if graph is not bipartite)
struct BipartiteMatching {
    int V;
    std::vector<std::vector<int>> to; // Adjacency list
    std::vector<int> dist;            // dist[i] = (Distance from i'th node)
    std::vector<int> match;           // match[i] = (Partner of i'th node) or -1 (No parter)
    std::vector<int> used, vv;
    std::vector<int> color; // color of each node(checking bipartition): 0/1/-1(not determined)

    BipartiteMatching() = default;
    BipartiteMatching(int V_) : V(V_), to(V_), match(V_, -1), used(V_), color(V_, -1) {}

    void add_edge(int u, int v) {
        assert(u >= 0 and u < V and v >= 0 and v < V and u != v);
        to[u].push_back(v);
        to[v].push_back(u);
    }

    void _bfs() {
        dist.assign(V, -1);
        std::vector<int> q;
        int lq = 0;
        for (int i = 0; i < V; i++) {
            if (!color[i] and !used[i]) q.push_back(i), dist[i] = 0;
        }

        while (lq < int(q.size())) {
            int now = q[lq++];
            for (auto nxt : to[now]) {
                int c = match[nxt];
                if (c >= 0 and dist[c] == -1) q.push_back(c), dist[c] = dist[now] + 1;
            }
        }
    }

    bool _dfs(int now) {
        vv[now] = true;
        for (auto nxt : to[now]) {
            int c = match[nxt];
            if (c < 0 or (!vv[c] and dist[c] == dist[now] + 1 and _dfs(c))) {
                match[nxt] = now, match[now] = nxt;
                used[now] = true;
                return true;
            }
        }
        return false;
    }

    bool _color_bfs(int root) {
        color[root] = 0;
        std::vector<int> q{root};
        int lq = 0;
        while (lq < int(q.size())) {
            int now = q[lq++], c = color[now];
            for (auto nxt : to[now]) {
                if (color[nxt] == -1) {
                    color[nxt] = !c, q.push_back(nxt);
                } else if (color[nxt] == c) {
                    return false;
                }
            }
        }
        return true;
    }

    int solve() {
        for (int i = 0; i < V; i++) {
            if (color[i] == -1 and !_color_bfs(i)) return -1;
        }
        int ret = 0;
        while (true) {
            _bfs();
            vv.assign(V, false);
            int flow = 0;
            for (int i = 0; i < V; i++) {
                if (!color[i] and !used[i] and _dfs(i)) flow++;
            }
            if (!flow) break;
            ret += flow;
        }
        return ret;
    }

    template <class OStream> friend OStream &operator<<(OStream &os, const BipartiteMatching &bm) {
        os << "{N=" << bm.V << ':';
        for (int i = 0; i < bm.V; i++) {
            if (bm.match[i] > i) os << '(' << i << '-' << bm.match[i] << "),";
        }
        return os << '}';
    }
};

// Directed graph library to find strongly connected components 
// 0-indexed directed graph
// Complexity: O(V + E)
struct DirectedGraphSCC {
    int V; // # of Vertices
    std::vector<std::vector<int>> to, from;
    std::vector<int> used; // Only true/false
    std::vector<int> vs;
    std::vector<int> cmp;
    int scc_num = -1;

    DirectedGraphSCC(int V = 0) : V(V), to(V), from(V), cmp(V) {}

    void _dfs(int v) {
        used[v] = true;
        for (auto t : to[v])
            if (!used[t]) _dfs(t);
        vs.push_back(v);
    }
    void _rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for (auto t : from[v])
            if (!used[t]) _rdfs(t, k);
    }

    void add_edge(int from_, int to_) {
        assert(from_ >= 0 and from_ < V and to_ >= 0 and to_ < V);
        to[from_].push_back(to_);
        from[to_].push_back(from_);
    }

    // Detect strongly connected components and return # of them.
    // Also, assign each vertex `v` the scc id `cmp[v]` (0-indexed)
    int FindStronglyConnectedComponents() {
        used.assign(V, false);
        vs.clear();
        for (int v = 0; v < V; v++)
            if (!used[v]) _dfs(v);
        used.assign(V, false);
        scc_num = 0;
        for (int i = (int)vs.size() - 1; i >= 0; i--)
            if (!used[vs[i]]) _rdfs(vs[i], scc_num++);
        return scc_num;
    }

    // Find and output the vertices that form a closed cycle.
    // output: {v_1, ..., v_C}, where C is the length of cycle,
    //         {} if there's NO cycle (graph is DAG)
    int _c, _init;
    std::vector<int> _ret_cycle;
    bool _dfs_detectcycle(int now, bool b0) {
        if (now == _init and b0) return true;
        for (auto nxt : to[now])
            if (cmp[nxt] == _c and !used[nxt]) {
                _ret_cycle.emplace_back(nxt), used[nxt] = 1;
                if (_dfs_detectcycle(nxt, true)) return true;
                _ret_cycle.pop_back();
            }
        return false;
    }
    std::vector<int> DetectCycle() {
        int ns = FindStronglyConnectedComponents();
        if (ns == V) return {};
        std::vector<int> cnt(ns);
        for (auto x : cmp) cnt[x]++;
        _c = std::find_if(cnt.begin(), cnt.end(), [](int x) { return x > 1; }) - cnt.begin();
        _init = std::find(cmp.begin(), cmp.end(), _c) - cmp.begin();
        used.assign(V, false);
        _ret_cycle.clear();
        _dfs_detectcycle(_init, false);
        return _ret_cycle;
    }

    // After calling `FindStronglyConnectedComponents()`, generate a new graph by uniting all
    // vertices belonging to the same component(The resultant graph is DAG).
    DirectedGraphSCC GenerateTopologicalGraph() {
        DirectedGraphSCC newgraph(scc_num);
        for (int s = 0; s < V; s++)
            for (auto t : to[s]) {
                if (cmp[s] != cmp[t]) newgraph.add_edge(cmp[s], cmp[t]);
            }
        return newgraph;
    }
};

// 2-SAT solver: Find a solution for  `(Ai v Aj) ^ (Ak v Al) ^ ... = true`
// - `nb_sat_vars`: Number of variables
// - Considering a graph with `2 * nb_sat_vars` vertices
// - Vertices [0, nb_sat_vars) means `Ai`
// - vertices [nb_sat_vars, 2 * nb_sat_vars) means `not Ai`
struct SATSolver : DirectedGraphSCC {
    int nb_sat_vars;
    std::vector<int> solution;
    SATSolver(int nb_variables = 0)
        : DirectedGraphSCC(nb_variables * 2), nb_sat_vars(nb_variables), solution(nb_sat_vars) {}
    void add_x_or_y_constraint(bool is_x_true, int x, bool is_y_true, int y) {
        assert(x >= 0 and x < nb_sat_vars);
        assert(y >= 0 and y < nb_sat_vars);
        if (!is_x_true) x += nb_sat_vars;
        if (!is_y_true) y += nb_sat_vars;
        add_edge((x + nb_sat_vars) % (nb_sat_vars * 2), y);
        add_edge((y + nb_sat_vars) % (nb_sat_vars * 2), x);
    }
    // Solve the 2-SAT problem. If no solution exists, return `false`.
    // Otherwise, dump one solution to `solution` and return `true`.
    bool run() {
        FindStronglyConnectedComponents();
        for (int i = 0; i < nb_sat_vars; i++) {
            if (cmp[i] == cmp[i + nb_sat_vars]) return false;
            solution[i] = cmp[i] > cmp[i + nb_sat_vars];
        }
        return true;
    }
};

// DulmageMendelsohn (DM) decomposition DM 
// return: [(W+0, W-0), (W+1,W-1),...,(W+(k+1), W-(k+1))]
//         : sequence of pair (left vetrices, right vertices)
//         - |W+0| < |W-0| or both empty
//         - |W+i| = |W-i| (i = 1, ..., k)
//         - |W+(k+1)| > |W-(k+1)| or both empty
//         - W is topologically sorted
// Example:
// (2, 2, [(0,0), (0,1), (1,0)]) => [([],[]),([0,],[1,]),([1,],[0,]),([],[]),]
// Complexity: O(N + (N + M) sqrt(N))
// Verified: https://yukicoder.me/problems/no/1615
std::vector<std::pair<std::vector<int>, std::vector<int>>>
dulmage_mendelsohn(int L, int R, const std::vector<std::pair<int, int>> &edges) {
    for (auto p : edges) {
        assert(0 <= p.first and p.first < L);
        assert(0 <= p.second and p.second < R);
    }

    BipartiteMatching bm(L + R);
    for (auto p : edges) bm.add_edge(p.first, L + p.second);
    bm.solve();

    DirectedGraphSCC scc(L + R);
    for (auto p : edges) scc.add_edge(p.first, L + p.second);
    for (int l = 0; l < L; ++l) {
        if (bm.match[l] >= L) scc.add_edge(bm.match[l], l);
    }

    int nscc = scc.FindStronglyConnectedComponents();
    std::vector<int> cmp_map(nscc, -2);

    std::vector<int> vis(L + R);
    std::vector<int> st;
    for (int c = 0; c < 2; ++c) {
        std::vector<std::vector<int>> to(L + R);
        auto color = [&L](int x) { return x >= L; };
        for (auto p : edges) {
            int u = p.first, v = L + p.second;
            if (color(u) != c) std::swap(u, v);
            to[u].push_back(v);
            if (bm.match[u] == v) to[v].push_back(u);
        }
        for (int i = 0; i < L + R; ++i) {
            if (bm.match[i] >= 0 or color(i) != c or vis[i]) continue;
            vis[i] = 1, st = {i};
            while (!st.empty()) {
                int now = st.back();
                cmp_map[scc.cmp[now]] = c - 1;
                st.pop_back();
                for (int nxt : to[now]) {
                    if (!vis[nxt]) vis[nxt] = 1, st.push_back(nxt);
                }
            }
        }
    }

    int nset = 1;
    for (int n = 0; n < nscc; ++n) {
        if (cmp_map[n] == -2) cmp_map[n] = nset++;
    }
    for (auto &x : cmp_map) {
        if (x == -1) x = nset;
    }
    nset++;

    std::vector<std::pair<std::vector<int>, std::vector<int>>> groups(nset);

    for (int l = 0; l < L; ++l) {
        if (bm.match[l] < 0) continue;
        int c = cmp_map[scc.cmp[l]];
        groups[c].first.push_back(l);
        groups[c].second.push_back(bm.match[l] - L);
    }
    for (int l = 0; l < L; ++l) {
        if (bm.match[l] >= 0) continue;
        int c = cmp_map[scc.cmp[l]];
        groups[c].first.push_back(l);
    }
    for (int r = 0; r < R; ++r) {
        if (bm.match[L + r] >= 0) continue;
        int c = cmp_map[scc.cmp[L + r]];
        groups[c].second.push_back(r);
    }

    return groups;
}

int main() {
    int L, R, M, Q;
    cin >> L >> R >> M >> Q;
    vector<pint> edges;
    map<pint, int> edge2id;
    REP(e, M) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges.emplace_back(u, v);
        edge2id[pint(u, v)] = e + 1;
    }
    auto dm = dulmage_mendelsohn(L, R, edges);
    dbg(dm);

    vector<pint> match;
    int nmatch = 0;
    lint wmatch = 0;
    for (auto [l, r] : dm) {
        REP(i, min(l.size(), r.size())) {
            int lid = l.at(i) + 1;
            int rid = -(r.at(i) + 1);
            int eid = edge2id.at(pint(l.at(i), r.at(i)));
            if (l.size() <= r.size()) match.emplace_back(lid, eid);
            else {
                match.emplace_back(rid, eid);
            }
            ++nmatch;
            wmatch += eid;
        }
    }
    dbg(nmatch);
    dbg(wmatch);
    dbg(match);

    while (Q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            auto [vid, eid] = match.back();
            match.pop_back();
            --nmatch;
            wmatch -= eid;
            cout << "1\n" << vid << '\n' << wmatch << endl;
        } else {
            cout << match.size() << '\n';
            for (auto [vid, eid] : match) cout << eid << ' ';
            cout << endl;
        }
    }
}