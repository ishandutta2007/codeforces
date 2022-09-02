#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios {
    fast_ios() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); };
} fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
template <typename T, typename V> void ndarray(vector<T> &vec, const V &val, int len) {
    vec.assign(len, val);
}
template <typename T, typename V, typename... Args>
void ndarray(vector<T> &vec, const V &val, int len, Args... args) {
    vec.resize(len), for_each(begin(vec), end(vec), [&](T &v) { ndarray(v, val, args...); });
}
template <typename T> bool chmax(T &m, const T q) {
    if (m < q) {
        m = q;
        return true;
    } else
        return false;
}
template <typename T> bool chmin(T &m, const T q) {
    if (m > q) {
        m = q;
        return true;
    } else
        return false;
}
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) {
    return make_pair(l.first + r.first, l.second + r.second);
}
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) {
    return make_pair(l.first - r.first, l.second - r.second);
}
template <typename T> vector<T> srtunq(vector<T> vec) {
    sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}
template <typename T> istream &operator>>(istream &is, vector<T> &vec) {
    for (auto &v : vec) is >> v;
    return is;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << '[';
    for (auto v : vec) os << v << ',';
    os << ']';
    return os;
}
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) {
    std::apply([&is](auto &&...args) { ((is >> args), ...); }, tpl);
    return is;
}
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) {
    std::apply([&os](auto &&...args) { ((os << args << ','), ...); }, tpl);
    return os;
}
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) {
    os << "deq[";
    for (auto v : vec) os << v << ',';
    os << ']';
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) {
    os << '{';
    for (auto v : vec) os << v << ',';
    os << '}';
    return os;
}
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) {
    os << '{';
    for (auto v : vec) os << v << ',';
    os << '}';
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) {
    os << '{';
    for (auto v : vec) os << v << ',';
    os << '}';
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) {
    os << '{';
    for (auto v : vec) os << v << ',';
    os << '}';
    return os;
}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) {
    os << '(' << pa.first << ',' << pa.second << ')';
    return os;
}
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) {
    os << '{';
    for (auto v : mp) os << v.first << "=>" << v.second << ',';
    os << '}';
    return os;
}
template <typename TK, typename TV, typename TH>
ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) {
    os << '{';
    for (auto v : mp) os << v.first << "=>" << v.second << ',';
    os << '}';
    return os;
}
#ifdef HITONANODE_LOCAL
#define dbg(x) (cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl)
#else
#define dbg(x)                                                                                               \
    {}
#endif

// Radix heap for unsigned integer
template <class uint, class label, typename std::enable_if<std::is_unsigned<uint>::value>::type * = nullptr>
class radix_heap {
    int sz;
    uint last;
    std::array<std::vector<std::pair<uint, label>>, std::numeric_limits<uint>::digits + 1> v;

    template <class U, typename std::enable_if<sizeof(U) == 4>::type * = nullptr>
    static inline int bucket(U x) noexcept {
        return x ? 32 - __builtin_clz(x) : 0;
    }
    template <class U, typename std::enable_if<sizeof(U) == 8>::type * = nullptr>
    static inline int bucket(U x) noexcept {
        return x ? 64 - __builtin_clzll(x) : 0;
    }

    void pull() {
        if (!v[0].empty()) return;
        int i = 1;
        while (v[i].empty()) ++i;
        last = v[i].back().first;
        for (int j = 0; j < int(v[i].size()); j++) last = std::min(last, v[i][j].first);
        for (int j = 0; j < int(v[i].size()); j++) {
            v[bucket(v[i][j].first ^ last)].emplace_back(std::move(v[i][j]));
        }
        v[i].clear();
    }

public:
    radix_heap() : sz(0), last(0) {}
    std::size_t size() const noexcept { return sz; }
    bool empty() const noexcept { return sz == 0; }
    void push(uint x, const label &val) { ++sz, v[bucket(x ^ last)].emplace_back(x, val); }
    void push(uint x, label &&val) { ++sz, v[bucket(x ^ last)].emplace_back(x, std::move(val)); }
    template <class... Args> void emplace(uint x, Args &&...args) {
        ++sz, v[bucket(x ^ last)].emplace_back(std::piecewise_construct, std::forward_as_tuple(x), std::forward_as_tuple(args...));
    }
    void pop() { pull(), --sz, v[0].pop_back(); }
    std::pair<uint, label> top() { return pull(), v[0].back(); }
    uint top_key() { return pull(), v[0].back().first; }
    label &top_label() { return pull(), v[0].back().second; }
    void clear() {
        sz = 0, last = 0;
        for (auto &vec : v) vec.clear();
    }
    void swap(radix_heap<uint, label> &a) { std::swap(sz, a.sz), std::swap(last, a.last), v.swap(a.v); }
};

// Minimum cost flow WITH NO NEGATIVE CYCLE (just negative cost edge is allowed)
// Verified:
// - SRM 770 Div1 Medium https://community.topcoder.com/stat?c=problem_statement&pm=15702
// - CodeChef LTIME98 Ancient Magic https://www.codechef.com/problems/ANCT
template <class Cap = long long, class Cost = long long, Cost INF_COST = std::numeric_limits<Cost>::max() / 2>
struct MinCostFlow {
    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
        template <class Ostream> friend Ostream &operator<<(Ostream &os, const _edge &e) {
            return os << '(' << e.to << ',' << e.rev << ',' << e.cap << ',' << e.cost << ')';
        }
    };
    bool _is_dual_infeasible;
    int V;
    std::vector<std::vector<_edge>> g;
    std::vector<Cost> dist;
    std::vector<int> prevv, preve;
    std::vector<Cost> dual; // dual[V]: potential
    std::vector<std::pair<int, int>> pos;

    bool _initialize_dual_dag() {
        std::vector<int> deg_in(V);
        for (int i = 0; i < V; i++) {
            for (const auto &e : g[i]) deg_in[e.to] += (e.cap > 0);
        }
        std::vector<int> st;
        st.reserve(V);
        for (int i = 0; i < V; i++) {
            if (!deg_in[i]) st.push_back(i);
        }
        for (int n = 0; n < V; n++) {
            if (int(st.size()) == n) return false; // Not DAG
            int now = st[n];
            for (const auto &e : g[now]) {
                if (!e.cap) continue;
                deg_in[e.to]--;
                if (deg_in[e.to] == 0) st.push_back(e.to);
                if (dual[e.to] >= dual[now] + e.cost) dual[e.to] = dual[now] + e.cost;
            }
        }
        return true;
    }

    bool _initialize_dual_spfa() { // Find feasible dual's when negative cost edges exist
        dual.assign(V, 0);
        std::queue<int> q;
        std::vector<int> in_queue(V);
        std::vector<int> nvis(V);
        for (int i = 0; i < V; i++) q.push(i), in_queue[i] = true;
        while (q.size()) {
            int now = q.front();
            q.pop(), in_queue[now] = false;
            if (nvis[now] > V) return false; // Negative cycle exists
            nvis[now]++;
            for (const auto &e : g[now]) {
                if (!e.cap) continue;
                if (dual[e.to] > dual[now] + e.cost) {
                    dual[e.to] = dual[now] + e.cost;
                    if (!in_queue[e.to]) in_queue[e.to] = true, q.push(e.to);
                }
            }
        }
        return true;
    }

    bool initialize_dual() {
        return !_is_dual_infeasible or _initialize_dual_dag() or _initialize_dual_spfa();
    }

    void _dijkstra(int s) { // O(ElogV)
        prevv.assign(V, -1);
        preve.assign(V, -1);
        dist.assign(V, INF_COST);
        dist[s] = 0;
        typedef typename std::make_unsigned<Cost>::type UCost;
        using P = std::pair<UCost, int>;
        radix_heap<UCost, int> q;
        // std::priority_queue<P, std::vector<P>, std::greater<P>> q;
        q.emplace(0, s);
        while (!q.empty()) {
            P p = q.top();
            q.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (int i = 0; i < (int)g[v].size(); i++) {
                _edge &e = g[v][i];
                UCost c = dist[v] + e.cost + dual[v] - dual[e.to];
                if (e.cap > 0 and dist[e.to] > c) {
                    dist[e.to] = c, prevv[e.to] = v, preve[e.to] = i;
                    assert(dist[e.to] >= 0);
                    q.emplace(dist[e.to], e.to);
                }
            }
        }
    }

    MinCostFlow(int V = 0) : _is_dual_infeasible(false), V(V), g(V), dual(V, 0) {
        static_assert(INF_COST > 0, "INF_COST must be positive");
    }

    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from and from < V);
        assert(0 <= to and to < V);
        assert(cap >= 0);
        if (cost < 0) _is_dual_infeasible = true;
        pos.emplace_back(from, g[from].size());
        g[from].push_back({to, (int)g[to].size() + (from == to), cap, cost});
        g[to].push_back({from, (int)g[from].size() - 1, (Cap)0, -cost});
        return int(pos.size()) - 1;
    }

    // Flush flow f from s to t. Graph must not have negative cycle.
    std::pair<Cap, Cost> flow(int s, int t, const Cap &flow_limit) {
        if (!initialize_dual()) throw; // Fail to find feasible dual
        Cost cost = 0;
        Cap flow_rem = flow_limit;
        while (flow_rem > 0) {
            _dijkstra(s);
            if (dist[t] == INF_COST) break;
            for (int v = 0; v < V; v++) dual[v] = std::min(dual[v] + dist[v], INF_COST);
            Cap d = flow_rem;
            for (int v = t; v != s; v = prevv[v]) d = std::min(d, g[prevv[v]][preve[v]].cap);
            flow_rem -= d;
            cost += d * (dual[t] - dual[s]);
            for (int v = t; v != s; v = prevv[v]) {
                _edge &e = g[prevv[v]][preve[v]];
                e.cap -= d;
                g[v][e.rev].cap += d;
            }
        }
        return std::make_pair(flow_limit - flow_rem, cost);
    }

    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
        template <class Ostream> friend Ostream &operator<<(Ostream &os, const edge &e) {
            return os << '(' << e.from << "->" << e.to << ',' << e.flow << '/' << e.cap << ",$" << e.cost << ')';
        }
    };

    edge get_edge(int edge_id) const {
        int m = int(pos.size());
        assert(0 <= edge_id and edge_id < m);
        auto _e = g[pos[edge_id].first][pos[edge_id].second];
        auto _re = g[_e.to][_e.rev];
        return {pos[edge_id].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost};
    }
    std::vector<edge> edges() const {
        std::vector<edge> ret(pos.size());
        for (int i = 0; i < int(pos.size()); i++) ret[i] = get_edge(i);
        return ret;
    }

    template <class Ostream> friend Ostream &operator<<(Ostream &os, const MinCostFlow &mcf) {
        os << "[MinCostFlow]V=" << mcf.V << ":";
        for (int i = 0; i < mcf.V; i++) {
            for (auto &e : mcf.g[i]) os << "\n" << i << "->" << e.to << ":cap" << e.cap << ",$" << e.cost;
        }
        return os;
    }
};

// MinCostFlow based on AtCoder Library, no namespace, no private variables, compatible with C++11
// **NO NEGATIVE COST EDGES**
// Reference: https://atcoder.github.io/ac-library/production/document_ja/mincostflow.html
// Remark: You can use [radix heap](https://github.com/iwiwi/radix-heap) for Dijkstra acceleration
template <class Cap, class Cost> struct mcf_graph {
    mcf_graph() {}
    mcf_graph(int n) : _n(n), g(n) {
        static_assert(std::numeric_limits<Cap>::max() > 0, "max() must be greater than 0");
    }

    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        assert(0 <= cost);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap, cost});
        g[to].push_back(_edge{from, from_id, 0, -cost});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{
            pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
        };
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result(m);
        for (int i = 0; i < m; i++) { result[i] = get_edge(i); }
        return result;
    }

    std::pair<Cap, Cost> flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }
    std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) { return slope(s, t, flow_limit).back(); }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, std::numeric_limits<Cap>::max());
    }

    std::vector<Cost> dual, dist;
    std::vector<int> pv, pe;
    std::vector<bool> vis;
    struct Q {
        Cost key;
        int to;
        bool operator<(Q r) const { return key > r.key; }
    };

    bool _dual_ref(int s, int t) {
        std::fill(dist.begin(), dist.end(), std::numeric_limits<Cost>::max());
        std::fill(vis.begin(), vis.end(), false);

        dist[s] = 0;
        typedef typename std::make_unsigned<Cost>::type UCost;
        using P = std::pair<UCost, int>;
        radix_heap<UCost, int> que;
        que.push(0, s);
        while (!que.empty()) {
            int v = que.top_label();
            que.pop();
            if (vis[v]) continue;
            vis[v] = true;
            if (v == t) break;
            // dist[v] = shortest(s, v) + dual[s] - dual[v]
            // dist[v] >= 0 (all reduced cost are positive)
            // dist[v] <= (n-1)C
            for (int i = 0; i < int(g[v].size()); i++) {
                auto e = g[v][i];
                if (vis[e.to] || !e.cap) continue;
                // |-dual[e.to] + dual[v]| <= (n-1)C
                // cost <= C - -(n-1)C + 0 = nC
                Cost cost = e.cost - dual[e.to] + dual[v];
                if (dist[e.to] - dist[v] > cost) {
                    dist[e.to] = dist[v] + cost;
                    pv[e.to] = v;
                    pe[e.to] = i;
                    que.push(dist[e.to], e.to);
                }
            }
        }
        if (!vis[t]) { return false; }

        for (int v = 0; v < _n; v++) {
            if (!vis[v]) continue;
            // dual[v] = dual[v] - dist[t] + dist[v]
            //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) + (shortest(s, v) + dual[s] - dual[v])
            //         = - shortest(s, t) + dual[t] + shortest(s, v)
            //         = shortest(s, v) - shortest(s, t) >= 0 - (n-1)C
            dual[v] -= dist[t] - dist[v];
        }
        return true;
    }

    std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);
        // variants (C = maxcost):
        // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0
        // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge
        dual.assign(_n, 0), dist.assign(_n, 0);
        pv.assign(_n, 0), pe.assign(_n, 0);
        vis.assign(_n, false);
        Cap flow = 0;
        Cost cost = 0, prev_cost_per_flow = -1;
        std::vector<std::pair<Cap, Cost>> result;
        result.push_back({flow, cost});
        while (flow < flow_limit) {
            if (!_dual_ref(s, t)) break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = pv[v]) { c = std::min(c, g[pv[v]][pe[v]].cap); }
            for (int v = t; v != s; v = pv[v]) {
                auto &e = g[pv[v]][pe[v]];
                e.cap -= c;
                g[v][e.rev].cap += c;
            }
            Cost d = -dual[s];
            flow += c;
            cost += c * d;
            if (prev_cost_per_flow == d) { result.pop_back(); }
            result.push_back({flow, cost});
            prev_cost_per_flow = d;
        }
        return result;
    }

    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };

    int _n;
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

template <typename CAP, typename COST> struct B_Flow {
    int N, E;
    COST cost_bias;
    bool infeasible;
    mcf_graph<CAP, COST> mcf;
    std::vector<CAP> b;
    std::vector<CAP> fbias;
    std::vector<int> fdir;
    std::vector<CAP> f;
    const std::vector<COST> &potential;

    B_Flow(int N = 0) : N(N), E(0), cost_bias(0), infeasible(false), mcf(N + 2), b(N), potential(mcf.dual) {}

    void add_supply(int v, CAP supply) { b[v] += supply; }
    void add_demand(int v, CAP demand) { b[v] -= demand; }
    void add_edge(int s, int t, CAP lower_cap, CAP upper_cap, COST cost) {
        assert(s >= 0 and s < N);
        assert(t >= 0 and t < N);
        if (lower_cap > upper_cap) {
            infeasible = true;
            return;
        }
        E++;
        if (s == t) {
            if (cost > 0)
                upper_cap = lower_cap;
            else
                lower_cap = upper_cap;
        }
        if (cost < 0) {
            fbias.emplace_back(lower_cap);
            fdir.emplace_back(-1);
            cost_bias += cost * upper_cap;
            b[s] -= upper_cap;
            b[t] += upper_cap;
            mcf.add_edge(t, s, upper_cap - lower_cap, -cost);
        } else {
            fbias.emplace_back(upper_cap);
            fdir.emplace_back(1);
            if (lower_cap < 0) {
                cost_bias += cost * lower_cap, b[s] -= lower_cap, b[t] += lower_cap;
                upper_cap -= lower_cap, lower_cap = 0;
            }
            if (lower_cap > 0) {
                cost_bias += cost * lower_cap;
                b[s] -= lower_cap;
                b[t] += lower_cap;
                upper_cap -= lower_cap;
            }
            mcf.add_edge(s, t, upper_cap, cost);
        }
    }

    std::pair<bool, COST> solve() {
        if (infeasible) { return std::make_pair(false, 0); }
        CAP bsum = 0, bsum_negative = 0;
        for (int i = 0; i < N; i++) {
            if (b[i] > 0) { mcf.add_edge(N, i, b[i], 0), bsum += b[i]; }
            if (b[i] < 0) { mcf.add_edge(i, N + 1, -b[i], 0), bsum_negative -= b[i]; }
        }
        if (bsum != bsum_negative) { return std::make_pair(false, 0); }
        std::fill(b.begin(), b.end(), 0);
        auto ret = mcf.flow(N, N + 1, bsum);
        COST cost_ret = cost_bias + ret.second;
        cost_bias = 0;
        bool succeeded = (ret.first == bsum);
        f = fbias;
        for (int i = 0; i < E; i++) {
            const std::pair<int, int> &p = mcf.pos[i];
            f[i] -= fdir[i] * mcf.g[p.first][p.second].cap;
        }
        return std::make_pair(succeeded, cost_ret);
    }
};
array<int, 4> dx{1, -1, 0, 0};
array<int, 4> dy{0, 0, 1, -1};
int main() {
    int N;
    cin >> N;
    vector A(N, vector<int>(N));
    cin >> A;
    B_Flow<lint, lint> flow(N * N);

    auto ij2v = [&](int i, int j) { return i * N + j; };
    auto adddiff = [&](int i1, int j1, int i2, int j2) {
        int v1 = ij2v(i1, j1);
        int v2 = ij2v(i2, j2);
        flow.add_edge(v1, v2, 0, 1, 0);
        flow.add_edge(v2, v1, 0, 1, 0);
    };
    auto add1 = [&](int i, int j, lint val) {
        int v = ij2v(i, j);
        flow.add_edge(0, v, 0, 1, -val);
        flow.add_edge(v, 0, 0, 1, val);
    };
    REP(i, N) REP(j, N) if (A[i][j] == 0) {
        if (A[i + 1][j] == 0) { adddiff(i, j, i + 1, j); }
        if (A[i][j + 1] == 0) { adddiff(i, j, i, j + 1); }
        REP(d, 4) {
            int a = A[i + dx[d]][j + dy[d]];
            if (a > 0) add1(i, j, a);
        }
    }

    auto [cap, cost] = flow.solve();
    lint ret = 0;
    REP(i, N) REP(j, N - 1) if (A[i][j] > 0 and A[i][j + 1] > 0) ret += abs(A[i][j] - A[i][j + 1]);
    REP(i, N - 1) REP(j, N) if (A[i][j] > 0 and A[i + 1][j] > 0) ret += abs(A[i][j] - A[i + 1][j]);
    cout << -cost + ret << '\n';
}