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
};

// Simple forward_list for MLE-sensitive situations
// Verify: <http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D>
template <typename T> struct light_forward_list {
    static std::vector<unsigned> ptr;
    static std::vector<T> val;
    unsigned head;
    light_forward_list() : head(0) {}
    void push_front(T x) {
        ptr.push_back(head), val.push_back(x);
        head = ptr.size() - 1;
    }
    struct iterator {
        unsigned p;
        iterator operator++() { return {p = ptr[p]}; }
        T &operator*() { return val[p]; }
        bool operator!=(const iterator &rhs) { return p != rhs.p; }
    };
    iterator begin() { return {head}; }
    iterator end() { return {0}; }
};
template <typename T> std::vector<unsigned> light_forward_list<T>::ptr = {0};
template <typename T> std::vector<T> light_forward_list<T>::val = {T()};

struct PathsOfLength2Decomposition {
    int V, E;
    std::vector<std::pair<int, int>> edges;
    std::vector<light_forward_list<std::pair<int, int>>> to_nonmst;
    std::vector<light_forward_list<std::pair<int, int>>> to_mst;
    UnionFind uf;
    void _init(int V_) {
        V = V_, E = 0;
        edges.clear();
        to_nonmst.assign(V, {});
        to_mst.assign(V, {});
        uf = UnionFind(V);
    }
    PathsOfLength2Decomposition(int V = 0) { _init(V); }
    void add_edge(int u, int v) {
        assert(u >= 0 and u < V);
        assert(v >= 0 and v < V);
        if (uf.unite(u, v)) {
            to_mst[u].push_front({E, v}), to_mst[v].push_front({E, u});
        } else {
            to_nonmst[u].push_front({E, v}), to_nonmst[v].push_front({E, u});
        }
        edges.emplace_back(u, v);
        E++;
    }

    std::vector<std::pair<int, int>> _ret;
    std::vector<char> _visited;
    std::vector<char> _edge_used;
    void _dfs(int now, int prv) {
        _visited[now] = 1;
        int prveid = -1;
        std::vector<int> available_edges;
        for (auto ev : to_mst[now]) {
            int eid, nxt;
            std::tie(eid, nxt) = ev;
            if (nxt == prv)
                prveid = eid;
            else {
                _dfs(nxt, now);
                if (!_edge_used[eid]) available_edges.push_back(eid);
            }
        }
        for (auto ev : to_nonmst[now]) {
            int eid, nxt;
            std::tie(eid, nxt) = ev;
            if (!_edge_used[eid]) available_edges.push_back(eid);
        }
        if ((available_edges.size() & 1) and prv != -1) available_edges.push_back(prveid);
        for (unsigned h = 0; h + 1 < available_edges.size(); h += 2) {
            int e1 = available_edges[h], e2 = available_edges[h + 1];
            _edge_used[e1] = _edge_used[e2] = 1;
            _ret.emplace_back(e1, e2);
        }
    }
    std::vector<std::pair<int, int>> run() { // 0-origin, 
        _ret.clear();
        _visited.assign(V, 0);
        _edge_used.assign(E, 0);
        for (int i = 0; i < V; i++) {
            if (!_visited[i]) _dfs(i, -1);
        }
        return _ret;
    }
};

plint red(plint x) {
    lint g = __gcd(x.first, x.second);
    return {x.first / g, x.second / g};
}

int main() {
    int N;
    cin >> N;
    map<plint, vector<int>> mp;
    vector<pair<plint, plint>> edges_;
    REP(i, N) {
        lint a, b, c, d;
        cin >> a >> b >> c >> d;
        plint p1 = red({(a + b) * d, b * c});
        plint p2 = red({a * d, b * (c + d)});
        mp[p1].push_back(i);
        mp[p2].push_back(i);
        edges_.emplace_back(p1, p2);
    }
    vector<plint> rats;
    for (auto [r, vs] : mp) rats.emplace_back(r);
    PathsOfLength2Decomposition graph(mp.size());

    for (auto [r1, r2] : edges_) {
        int v1 = lower_bound(ALL(rats), r1) - rats.begin();
        int v2 = lower_bound(ALL(rats), r2) - rats.begin();
        graph.add_edge(v1, v2);
    }


    auto ret = graph.run();
    cout << ret.size() << '\n';
    for (auto [a, b] : ret) cout << a + 1 << ' ' << b + 1 << '\n';
}