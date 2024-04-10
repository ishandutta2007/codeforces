#include <bits/stdc++.h>
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
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os; }
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
#else
#define dbg(x) (x)
#endif

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

    // After calling `FindStronglyConnectedComponents()`, generate a new graph by uniting all vertices
    // belonging to the same component(The resultant graph is DAG).
    DirectedGraphSCC GenerateTopologicalGraph() {
        DirectedGraphSCC newgraph(scc_num);
        for (int s = 0; s < V; s++)
            for (auto t : to[s]) {
                if (cmp[s] != cmp[t]) newgraph.add_edge(cmp[s], cmp[t]);
            }
        return newgraph;
    }
};


template <typename T>
struct WeightedUnionFind {
    std::vector<int> par, sz;
    std::vector<T> pot;
    WeightedUnionFind(int N = 0) : par(N), sz(N, 1), pot(N) { std::iota(par.begin(), par.end(), 0); }
    int find(int x) {
        if (par[x] != x) {
            int r = find(par[x]);
            pot[x] = pot[x] + pot[par[x]], par[x] = r;
        }
        return par[x];
    }
    bool unite(int s, int t, T rel_diff) {
        // Relate s and t by t = s + rel_diff
        // Return false iff contradiction happens.
        rel_diff = rel_diff + weight(s) + (-weight(t));
        if ((s = find(s)) == (t = find(t))) return rel_diff == 0;
        if (sz[s] < sz[t]) std::swap(s, t), rel_diff = -rel_diff;
        par[t] = s, sz[s] += sz[t], pot[t] = rel_diff;
        return true;
    }
    T weight(int x) {
        find(x);
        return pot[x];
    }
    T diff(int s, int t) { return weight(t) + (-weight(s)); }
    int count(int x) { return sz[find(x)]; }
    bool same(int s, int t) { return find(s) == find(t); }
};

int main() {
    int N, M;
    cin >> N >> M;
    DirectedGraphSCC graph(N);
    vector<vector<pint>> to(N);
    REP(m, M) {
        int s, t, w;
        cin >> s >> t >> w;
        s--, t--;
        graph.add_edge(s, t);
        to[s].emplace_back(t, w);
    }
    const int K = graph.FindStronglyConnectedComponents();
    WeightedUnionFind<lint> mst(N);

    using tpl = tuple<int, int, int>;
    vector<tpl> add_edges;
    REP(s, N) {
        for (auto [t, w] : to[s]) {
            if (graph.cmp[s] == graph.cmp[t]) {
                if (mst.unite(s, t, w)) {

                } else {
                    add_edges.emplace_back(s, t, w);
                }
            }
        }
    }
    dbg(add_edges);
    vector<lint> loop_gcds(K);
    for (auto [s, t, w] : add_edges) {
        int c = graph.cmp[s];
        lint loop_len = abs(mst.diff(s, t) - w);
        dbg(loop_len);
        loop_gcds[c] = __gcd(loop_gcds[c], loop_len);
    }

    dbg(loop_gcds);
    int Q;
    cin >> Q;
    while (Q--) {
        int v;
        lint s;
        lint t;
        cin >> v >> s >> t;
        v--;
        const lint g = loop_gcds[graph.cmp[v]];
        lint tt = __gcd(g, t);
        dbg(s);
        dbg(tt);
        cout << (s % tt == 0 ? "YES" : "NO") << '\n';
    }
}