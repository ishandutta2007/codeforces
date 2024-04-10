#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
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

// Bipartite matching of undirected bipartite graph (Hopcroft-Karp)
// <https://ei1333.github.io/luzhiled/snippets/graph/hopcroft-karp.html>
// Comprexity: O(EsqrtV)
// int solve(): enumerate maximum number of matching / return -1 (if graph is not bipartite)
struct BipartiteMatching {
    int V;
    std::vector<std::vector<int>> to; // Adjacency list
    std::vector<int> dist;            // dist[i] = (Distance from i'th node)
    std::vector<int> match;           // match[i] = (Partner of i'th node) or -1 (No parter)
    std::vector<int> used, vv;        //
    std::vector<int> color;           // color of each node(checking bipartition): 0/1/-1(not determined)

    BipartiteMatching() = default;
    BipartiteMatching(int V_) : V(V_), to(V_), match(V_, -1), used(V_), color(V_, -1) {}

    void add_edge(int u, int v) {
        assert(u >= 0 and u < V and v >= 0 and v < V and u != v);
        to[u].push_back(v);
        to[v].push_back(u);
    }

    void bfs() {
        dist.assign(V, -1);
        std::queue<int> q;
        for (int i = 0; i < V; i++) {
            if (!color[i] and !used[i]) { q.emplace(i), dist[i] = 0; }
        }

        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (auto nxt : to[now]) {
                int c = match[nxt];
                if (c >= 0 and dist[c] == -1) { q.emplace(c), dist[c] = dist[now] + 1; }
            }
        }
    }

    bool dfs(int now) {
        vv[now] = true;
        for (auto nxt : to[now]) {
            int c = match[nxt];
            if (c < 0 or (!vv[c] and dist[c] == dist[now] + 1 and dfs(c))) {
                match[nxt] = now, match[now] = nxt;
                used[now] = true;
                return true;
            }
        }
        return false;
    }

    bool _color_bfs(int root) {
        color[root] = 0;
        std::queue<int> q;
        q.emplace(root);
        while (!q.empty()) {
            int now = q.front(), c = color[now];
            q.pop();
            for (auto nxt : to[now])
                if (color[nxt] == -1)
                    color[nxt] = !c, q.emplace(nxt);
                else if (color[nxt] == c)
                    return false;
        }
        return true;
    }

    int solve() {
        for (int i = 0; i < V; i++)
            if (color[i] == -1) {
                if (!_color_bfs(i)) return -1;
            }
        int ret = 0;
        while (true) {
            bfs();
            vv.assign(V, false);
            int flow = 0;
            for (int i = 0; i < V; i++)
                if (!color[i] and !used[i] and dfs(i)) flow++;
            if (!flow) break;
            ret += flow;
        }
        return ret;
    }

    friend std::ostream &operator<<(std::ostream &os, const BipartiteMatching &bm) {
        os << "{N=" << bm.V << ':';
        for (int i = 0; i < bm.V; i++)
            if (bm.match[i] > i) { os << '(' << i << '-' << bm.match[i] << "),"; }
        os << '}';
        return os;
    }
};


vector<int> solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<pint> edges;
    vector<int> alive(N * 2, 1);
    REP(e, M) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        edges.emplace_back(s, t + N);
    }
    vector<lint> X(N), Y(N);
    REP(i, N) cin >> X[i] >> Y[i];

    BipartiteMatching bm(N * 2);
    for (auto [s, t] : edges) bm.add_edge(s, t);
    int k = bm.solve();
    vector<lint> req_cut(N, 1 << 30);
    FOR(i, k, req_cut.size()) req_cut[i] = 0;
    int cost = 0;

    vector<int> erase_history;
    dbg(edges);
    while (k) {
        dbg(k);
        vector<int> cand;
        REP(i, N) if (bm.match[i] >= 0) cand = {i, bm.match[i]};

        REP(i, N * 2) if (bm.match[i] >= 0) {
            BipartiteMatching bm(N * 2);
            for (auto [s, t] : edges) {
                if (alive[s] and alive[t] and s != i and t != i) bm.add_edge(s, t);
            }
            int t = bm.solve();
            if (t < k) {
                cand = {i};
                break;
            }
        }
        dbg(cand);

        for (auto s : cand) alive[s] = 0, cost++, erase_history.push_back(s);
        bm = BipartiteMatching(N * 2);
        for (auto [s, t] : edges) {
            if (alive[s] and alive[t]) bm.add_edge(s, t);
        }
        int knew = bm.solve();
        FOR(i, knew, k) req_cut[i] = cost;
        k = knew;
    }
    req_cut.pop_back();
    reverse(req_cut.begin(), req_cut.end());
    dbg(erase_history);

    constexpr lint INF = 1LL << 60;
    vector dp(N + 1, vector<lint>(M + 1, -INF));
    vector prv(N + 1, vector<lint>(M + 1));
    dp[0][0] = 0;
    REP(i, N) REP(m, M + 1) if (dp[i][m] > -INF) {
        REP(madd, M + 1 - m) {
            if (m + madd >= req_cut[i]) {
                if (chmax(dp[i + 1][m + madd], dp[i][m] + max(0LL, X[i] - madd * Y[i]))) {
                    prv[i + 1][m + madd] = m;
                }
            }
        }
    }
    int n = N, m = erase_history.size();
    vector<int> ret;
    while (n) {
        int mnxt = prv[n][m];
        REP(t, m - mnxt) {
            auto x = erase_history.back();
            erase_history.pop_back();
            if (x < N) ret.push_back(x + 1);
            else ret.push_back(-(x - N + 1));
        }
        m = mnxt, n--;
        ret.push_back(0);
    }
    ret.pop_back();
    reverse(ret.begin(), ret.end());
    int i = 0, zerocnt = 0;
    while (zerocnt < K) {
        zerocnt += (ret[i] == 0);
        i++;
    }
    while (ret.size() > i) ret.pop_back();
    // dbg(*max_element(dp.back().begin(), dp.back().end()));
    return ret;
}

int main() {
    auto v = solve();
    cout << v.size() << '\n';
    for (auto x : v) cout << x << ' ';
    cout << '\n';
}