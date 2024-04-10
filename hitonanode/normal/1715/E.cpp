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

template <typename T, T INF = std::numeric_limits<T>::max() / 2, int INVALID = -1>
struct shortest_path {
    int V, E;
    bool single_positive_weight;
    T wmin, wmax;

    std::vector<std::pair<int, T>> tos;
    std::vector<int> head;
    std::vector<std::tuple<int, int, T>> edges;

    void build_() {
        if (int(tos.size()) == E and int(head.size()) == V + 1) return;
        tos.resize(E);
        head.assign(V + 1, 0);
        for (const auto &e : edges) ++head[std::get<0>(e) + 1];
        for (int i = 0; i < V; ++i) head[i + 1] += head[i];
        auto cur = head;
        for (const auto &e : edges) {
            tos[cur[std::get<0>(e)]++] = std::make_pair(std::get<1>(e), std::get<2>(e));
        }
    }

    shortest_path(int V = 0) : V(V), E(0), single_positive_weight(true), wmin(0), wmax(0) {}
    void add_edge(int s, int t, T w) {
        assert(0 <= s and s < V);
        assert(0 <= t and t < V);
        edges.emplace_back(s, t, w);
        ++E;
        if (w > 0 and wmax > 0 and wmax != w) single_positive_weight = false;
        wmin = std::min(wmin, w);
        wmax = std::max(wmax, w);
    }

    void add_bi_edge(int u, int v, T w) {
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    std::vector<T> dist;
    std::vector<int> prev;

    // Dijkstra algorithm
    // - Requirement: wmin >= 0
    // - Complexity: O(E log E)
    using Pque = std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,
                                     std::greater<std::pair<T, int>>>;
    template <class Heap = Pque> void dijkstra(int s, int t = INVALID) {
        assert(0 <= s and s < V);
        build_();
        dist.assign(V, INF);
        prev.assign(V, INVALID);
        dist[s] = 0;
        Heap pq;
        pq.emplace(0, s);
        while (!pq.empty()) {
            T d;
            int v;
            std::tie(d, v) = pq.top();
            pq.pop();
            if (t == v) return;
            if (dist[v] < d) continue;
            for (int e = head[v]; e < head[v + 1]; ++e) {
                const auto &nx = tos[e];
                T dnx = d + nx.second;
                if (dist[nx.first] > dnx) {
                    dist[nx.first] = dnx, prev[nx.first] = v;
                    pq.emplace(dnx, nx.first);
                }
            }
        }
    }

    // Dijkstra algorithm
    // - Requirement: wmin >= 0
    // - Complexity: O(V^2 + E)
    void dijkstra_vquad(int s, int t = INVALID) {
        assert(0 <= s and s < V);
        build_();
        dist.assign(V, INF);
        prev.assign(V, INVALID);
        dist[s] = 0;
        std::vector<char> fixed(V, false);
        while (true) {
            int r = INVALID;
            T dr = INF;
            for (int i = 0; i < V; i++) {
                if (!fixed[i] and dist[i] < dr) r = i, dr = dist[i];
            }
            if (r == INVALID or r == t) break;
            fixed[r] = true;
            int nxt;
            T dx;
            for (int e = head[r]; e < head[r + 1]; ++e) {
                std::tie(nxt, dx) = tos[e];
                if (dist[nxt] > dist[r] + dx) dist[nxt] = dist[r] + dx, prev[nxt] = r;
            }
        }
    }

    // Bellman-Ford algorithm
    // - Requirement: no negative loop
    // - Complexity: O(VE)
    bool bellman_ford(int s, int nb_loop) {
        assert(0 <= s and s < V);
        build_();
        dist.assign(V, INF), prev.assign(V, INVALID);
        dist[s] = 0;
        for (int l = 0; l < nb_loop; l++) {
            bool upd = false;
            for (int v = 0; v < V; v++) {
                if (dist[v] == INF) continue;
                for (int e = head[v]; e < head[v + 1]; ++e) {
                    const auto &nx = tos[e];
                    T dnx = dist[v] + nx.second;
                    if (dist[nx.first] > dnx) dist[nx.first] = dnx, prev[nx.first] = v, upd = true;
                }
            }
            if (!upd) return true;
        }
        return false;
    }

    // Bellman-ford algorithm using deque
    // - Requirement: no negative loop
    // - Complexity: O(VE)
    void spfa(int s) {
        assert(0 <= s and s < V);
        build_();
        dist.assign(V, INF);
        prev.assign(V, INVALID);
        dist[s] = 0;
        std::deque<int> q;
        std::vector<char> in_queue(V);
        q.push_back(s), in_queue[s] = 1;
        while (!q.empty()) {
            int now = q.front();
            q.pop_front(), in_queue[now] = 0;
            for (int e = head[now]; e < head[now + 1]; ++e) {
                const auto &nx = tos[e];
                T dnx = dist[now] + nx.second;
                int nxt = nx.first;
                if (dist[nxt] > dnx) {
                    dist[nxt] = dnx;
                    if (!in_queue[nxt]) {
                        if (q.size() and dnx < dist[q.front()]) { // Small label first optimization
                            q.push_front(nxt);
                        } else {
                            q.push_back(nxt);
                        }
                        prev[nxt] = now, in_queue[nxt] = 1;
                    }
                }
            }
        }
    }

    // 01-BFS
    // - Requirement: all weights must be 0 or w (positive constant).
    // - Complexity: O(V + E)
    void zero_one_bfs(int s, int t = INVALID) {
        assert(0 <= s and s < V);
        build_();
        dist.assign(V, INF), prev.assign(V, INVALID);
        dist[s] = 0;
        std::vector<int> q(V * 4);
        int ql = V * 2, qr = V * 2;
        q[qr++] = s;
        while (ql < qr) {
            int v = q[ql++];
            if (v == t) return;
            for (int e = head[v]; e < head[v + 1]; ++e) {
                const auto &nx = tos[e];
                T dnx = dist[v] + nx.second;
                if (dist[nx.first] > dnx) {
                    dist[nx.first] = dnx, prev[nx.first] = v;
                    if (nx.second) {
                        q[qr++] = nx.first;
                    } else {
                        q[--ql] = nx.first;
                    }
                }
            }
        }
    }

    // Dial's algorithm
    // - Requirement: wmin >= 0
    // - Complexity: O(wmax * V + E)
    void dial(int s, int t = INVALID) {
        assert(0 <= s and s < V);
        build_();
        dist.assign(V, INF), prev.assign(V, INVALID);
        dist[s] = 0;
        std::vector<std::vector<std::pair<int, T>>> q(wmax + 1);
        q[0].emplace_back(s, dist[s]);
        int ninq = 1;

        int cur = 0;
        T dcur = 0;
        for (; ninq; ++cur, ++dcur) {
            if (cur == wmax + 1) cur = 0;
            while (!q[cur].empty()) {
                int v = q[cur].back().first;
                T dnow = q[cur].back().second;
                q[cur].pop_back(), --ninq;
                if (v == t) return;
                if (dist[v] < dnow) continue;

                for (int e = head[v]; e < head[v + 1]; ++e) {
                    const auto &nx = tos[e];
                    T dnx = dist[v] + nx.second;
                    if (dist[nx.first] > dnx) {
                        dist[nx.first] = dnx, prev[nx.first] = v;
                        int nxtcur = cur + int(nx.second);
                        if (nxtcur >= int(q.size())) nxtcur -= q.size();
                        q[nxtcur].emplace_back(nx.first, dnx), ++ninq;
                    }
                }
            }
        }
    }

    // Solver for DAG
    // - Requirement: graph is DAG
    // - Complexity: O(V + E)
    bool dag_solver(int s) {
        assert(0 <= s and s < V);
        build_();
        dist.assign(V, INF), prev.assign(V, INVALID);
        dist[s] = 0;
        std::vector<int> indeg(V, 0);
        std::vector<int> q(V * 2);
        int ql = 0, qr = 0;
        q[qr++] = s;
        while (ql < qr) {
            int now = q[ql++];
            for (int e = head[now]; e < head[now + 1]; ++e) {
                const auto &nx = tos[e];
                ++indeg[nx.first];
                if (indeg[nx.first] == 1) q[qr++] = nx.first;
            }
        }
        ql = qr = 0;
        q[qr++] = s;
        while (ql < qr) {
            int now = q[ql++];
            for (int e = head[now]; e < head[now + 1]; ++e) {
                const auto &nx = tos[e];
                --indeg[nx.first];
                if (dist[nx.first] > dist[now] + nx.second)
                    dist[nx.first] = dist[now] + nx.second, prev[nx.first] = now;
                if (indeg[nx.first] == 0) q[qr++] = nx.first;
            }
        }
        return *max_element(indeg.begin(), indeg.end()) == 0;
    }

    // Retrieve a sequence of vertex ids that represents shortest path [s, ..., goal]
    // If not reachable to goal, return {}
    std::vector<int> retrieve_path(int goal) const {
        assert(int(prev.size()) == V);
        assert(0 <= goal and goal < V);
        if (dist[goal] == INF) return {};
        std::vector<int> ret{goal};
        while (prev[goal] != INVALID) {
            goal = prev[goal];
            ret.push_back(goal);
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }

    void solve(int s, int t = INVALID) {
        if (wmin >= 0) {
            if (single_positive_weight) {
                zero_one_bfs(s, t);
            } else if (wmax <= 10) {
                dial(s, t);
            } else {
                if ((long long)V * V < (E << 4)) {
                    dijkstra_vquad(s, t);
                } else {
                    dijkstra(s, t);
                }
            }
        } else {
            bellman_ford(s, V);
        }
    }

    // Warshall-Floyd algorithm
    // - Requirement: no negative loop
    // - Complexity: O(E + V^3)
    std::vector<std::vector<T>> floyd_warshall() {
        build_();
        std::vector<std::vector<T>> dist2d(V, std::vector<T>(V, INF));
        for (int i = 0; i < V; i++) {
            dist2d[i][i] = 0;
            for (const auto &e : edges) {
                int s = std::get<0>(e), t = std::get<1>(e);
                dist2d[s][t] = std::min(dist2d[s][t], std::get<2>(e));
            }
        }
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                if (dist2d[i][k] == INF) continue;
                for (int j = 0; j < V; j++) {
                    if (dist2d[k][j] == INF) continue;
                    dist2d[i][j] = std::min(dist2d[i][j], dist2d[i][k] + dist2d[k][j]);
                }
            }
        }
        return dist2d;
    }

    void to_dot(std::string filename = "shortest_path") const {
        std::ofstream ss(filename + ".DOT");
        ss << "digraph{\n";
        build_();
        for (int i = 0; i < V; i++) {
            for (int e = head[i]; e < head[i + 1]; ++e) {
                ss << i << "->" << tos[e].first << "[label=" << tos[e].second << "];\n";
            }
        }
        ss << "}\n";
        ss.close();
        return;
    }
};


// Convex Hull Trick for monotone insertions
// - is_minimizer: if true, calculates min. Otherwise, calculates max.
// - add_line(a, b): Add `y = ax + b`, O(1) if `a` must be largest or smallest, or do nothing otherwise.
// - add_convex_parabola(c, a, b): Add `y = c(x - a)^2 + b`, c is constant
// - get(x): Calculate min/max. value of `y = ax + b`'s at point x, O(logN)
// - parabola_get(c, x): Caclculate min/max. value of `y = c(x - a)^2 + b`'s
// - merge(): merge two CHTs in linear time
// Verified: https://codeforces.com/gym/101806/problem/R
//           https://atcoder.jp/contests/pakencamp-2020-day2/submissions/19262614
template <bool is_minimizer, typename T_CHT = long long, typename T_MP = __int128, T_CHT INF = 1LL << 61>
struct AddMonotoneConvexHullTrick {
    std::deque<std::pair<T_CHT, T_CHT>> q; // [(a0, b0), ..., (ai, bi), ...], a0 > a1 > a2 > ...
    AddMonotoneConvexHullTrick() {}
    void add_line(T_CHT a, T_CHT b) { // Add y = ax + b
        if (!is_minimizer) a = -a, b = -b;
        if (q.empty()) {
            q.emplace_back(a, b);
        } else if (q.size() == 1) {
            if (q.front().first == a) {
                if (b < q.front().second) q.front().second = b;
            } else if (q.front().first > a) {
                q.emplace_back(a, b);
            } else {
                q.emplace_front(a, b);
            }
        } else if (q.back().first >= a) {
            while (q.size() > 1u) {
                if (q.back().first == a and q.back().second <= b) return;
                int sz = q.size();
                T_MP l = (T_MP)(q.back().second - q[sz - 2].second) *
                         (q.back().first - a); // Overflow might occur here.
                T_MP r = (T_MP)(b - q.back().second) * (q[sz - 2].first - q.back().first);
                if (l < r) break;
                q.pop_back();
            }
            q.emplace_back(a, b);
        } else if (q[0].first <= a) {
            while (q.size() > 1u) {
                if (q[0].first == a and q[0].second <= b) return;
                T_MP l = (T_MP)(q[0].second - q[1].second) * (q[0].first - a);
                T_MP r = (T_MP)(b - q[0].second) * (q[1].first - q[0].first);
                if (l > r) break;
                q.pop_front();
            }
            q.emplace_front(a, b);
        }
    }

    T_CHT _get_idx(int i, T_CHT x) const { return q[i].first * x + q[i].second; }

    T_CHT get(T_CHT x) const {
        if (q.empty()) return INF * (is_minimizer ? 1 : -1);
        int l = 0, r = q.size();
        while (l + 1 < r) {
            int c = (l + r) / 2, clo = c - 1;
            (_get_idx(clo, x) >= _get_idx(c, x) ? l : r) = c;
        }
        return _get_idx(l, x) * (is_minimizer ? 1 : -1);
    }

    void add_convex_parabola(T_CHT c, T_CHT a, T_CHT b) { add_line(c * a * (-2), c * a * a + b); }
    T_CHT parabola_get(T_CHT c, T_CHT x) const { return get(x) + c * x * x; }

    static AddMonotoneConvexHullTrick
    merge(const AddMonotoneConvexHullTrick &cht1, const AddMonotoneConvexHullTrick &cht2) {
        AddMonotoneConvexHullTrick ret;
        auto i1 = cht1.q.begin(), i2 = cht2.q.begin();
        static const T_CHT sgn = is_minimizer ? 1 : -1;
        T_CHT a = 0, b = 0;
        while (i1 != cht1.q.end() and i2 != cht2.q.end()) {
            if (i1->first == i2->first) {
                a = i1->first, b = std::min(i1->second, i2->second);
                i1++, i2++;
            } else if (i1->first > i2->first) {
                a = i1->first, b = i1->second, i1++;
            } else {
                a = i2->first, b = i2->second, i2++;
            }
            ret.add_line(a * sgn, b * sgn);
        }
        while (i1 != cht1.q.end()) ret.add_line(i1->first * sgn, i1->second * sgn), i1++;
        while (i2 != cht2.q.end()) ret.add_line(i2->first * sgn, i2->second * sgn), i2++;
        return ret;
    }
};


int main() {
    int N, M, K;
    cin >> N >> M >> K;
    shortest_path<lint> g0(N + 1);
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g0.add_bi_edge(u, v, w);
    }
    constexpr lint INF = 1LL << 50;
    vector<lint> dp(N, INF);
    dp[0] = 0;
    REP(_, K + 1) {
        auto g = g0;
        REP(i, N) g.add_edge(N, i, dp[i]);
        g.solve(N);
        REP(i, N) dp[i] = g.dist[i];
        if (_ == K) break;
        dbg("Dijkstra");
        dbg(dp);
        dbg("CHT");
        AddMonotoneConvexHullTrick<true> cht;
        REP(i, N) cht.add_convex_parabola(1, i, dp[i]);
        REP(i, N) dp[i] = cht.parabola_get(1, i);
        dbg(dp);
    }
    for (auto x : dp) cout << x << ' ';
    cout << '\n';
}