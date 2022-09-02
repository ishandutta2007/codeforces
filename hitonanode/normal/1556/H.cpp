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


#include <algorithm>
#include <cassert>
#include <deque>
#include <fstream>
#include <functional>
#include <limits>
#include <queue>
#include <string>
#include <utility>
#include <vector>

template <typename T, T INF = std::numeric_limits<T>::max() / 2, int INVALID = -1> struct ShortestPath {
    int V, E;
    bool single_positive_weight;
    T wmin, wmax;
    std::vector<std::vector<std::pair<int, T>>> to;

    ShortestPath(int V = 0) : V(V), E(0), single_positive_weight(true), wmin(0), wmax(0), to(V) {}
    void add_edge(int s, int t, T w) {
        assert(0 <= s and s < V);
        assert(0 <= t and t < V);
        to[s].emplace_back(t, w);
        E++;
        if (w > 0 and wmax > 0 and wmax != w) single_positive_weight = false;
        wmin = std::min(wmin, w);
        wmax = std::max(wmax, w);
    }

    std::vector<T> dist;
    std::vector<int> prev;

    // Dijkstra algorithm
    // Complexity: O(E log E)
    void Dijkstra(int s) {
        assert(0 <= s and s < V);
        dist.assign(V, INF);
        dist[s] = 0;
        prev.assign(V, INVALID);
        using P = std::pair<T, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
        pq.emplace(0, s);
        while (!pq.empty()) {
            T d;
            int v;
            std::tie(d, v) = pq.top();
            pq.pop();
            if (dist[v] < d) continue;
            for (auto nx : to[v]) {
                T dnx = d + nx.second;
                if (dist[nx.first] > dnx) {
                    dist[nx.first] = dnx, prev[nx.first] = v;
                    pq.emplace(dnx, nx.first);
                }
            }
        }
    }
    void DijkstraWithPotential(int s, const std::vector<T> &p) {
        assert(0 <= s and s < V);
        assert(int(p.size()) == V);
        assert(p[s] == 0);
        dist.assign(V, INF);
        dist[s] = 0;
        prev.assign(V, INVALID);
        using P = std::pair<T, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
        pq.emplace(0, s);
        while (!pq.empty()) {
            T d;
            int v;
            std::tie(d, v) = pq.top();
            pq.pop();
            if (dist[v] < d) continue;
            for (auto nx : to[v]) {
                auto len = nx.second - p[nx.first] + p[v];
                assert(len >= 0);
                T dnx = d + len;
                if (dist[nx.first] > dnx) {
                    dist[nx.first] = dnx, prev[nx.first] = v;
                    pq.emplace(dnx, nx.first);
                }
            }
        }
        for (int v = 0; v < V; v++) {
            if (dist[v] != INF) dist[v] += p[v] - p[s];
        }
    }

    // Dijkstra algorithm, O(V^2 + E)
    void DijkstraVquad(int s) {
        assert(0 <= s and s < V);
        dist.assign(V, INF);
        dist[s] = 0;
        prev.assign(V, INVALID);
        std::vector<char> fixed(V, false);
        while (true) {
            int r = INVALID;
            T dr = INF;
            for (int i = 0; i < V; i++) {
                if (!fixed[i] and dist[i] < dr) r = i, dr = dist[i];
            }
            if (r == INVALID) break;
            fixed[r] = true;
            int nxt;
            T dx;
            for (auto p : to[r]) {
                std::tie(nxt, dx) = p;
                if (dist[nxt] > dist[r] + dx) dist[nxt] = dist[r] + dx, prev[nxt] = r;
            }
        }
    }

    // Bellman-Ford algorithm
    // Complexity: O(VE)
    bool BellmanFord(int s, int nb_loop) {
        assert(0 <= s and s < V);
        dist.assign(V, INF), prev.assign(V, INVALID);
        dist[s] = 0;
        for (int l = 0; l < nb_loop; l++) {
            bool upd = false;
            for (int v = 0; v < V; v++) {
                if (dist[v] == INF) continue;
                for (auto nx : to[v]) {
                    T dnx = dist[v] + nx.second;
                    if (dist[nx.first] > dnx) dist[nx.first] = dnx, prev[nx.first] = v, upd = true;
                }
            }
            if (!upd) return true;
        }
        return false;
    }

    // Bellman-ford algorithm using queue (deque)
    // Complexity: O(VE)
    // Requirement: no negative loop
    void SPFA(int s) {
        assert(0 <= s and s < V);
        dist.assign(V, INF);
        prev.assign(V, INVALID);
        std::deque<int> q;
        std::vector<char> in_queue(V);
        dist[s] = 0;
        q.push_back(s), in_queue[s] = 1;
        while (!q.empty()) {
            int now = q.front();
            q.pop_front(), in_queue[now] = 0;
            for (auto nx : to[now]) {
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

    void ZeroOneBFS(int s) {
        assert(0 <= s and s < V);
        dist.assign(V, INF), prev.assign(V, INVALID);
        dist[s] = 0;
        std::deque<int> que;
        que.push_back(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop_front();
            for (auto nx : to[v]) {
                T dnx = dist[v] + nx.second;
                if (dist[nx.first] > dnx) {
                    dist[nx.first] = dnx, prev[nx.first] = v;
                    if (nx.second) {
                        que.push_back(nx.first);
                    } else {
                        que.push_front(nx.first);
                    }
                }
            }
        }
    }

    bool dag_solver(int s) {
        assert(0 <= s and s < V);
        std::vector<int> indeg(V, 0);
        std::queue<int> que;
        que.push(s);
        while (que.size()) {
            int now = que.front();
            que.pop();
            for (auto nx : to[now]) {
                indeg[nx.first]++;
                if (indeg[nx.first] == 1) que.push(nx.first);
            }
        }
        dist.assign(V, INF), prev.assign(V, INVALID);
        dist[s] = 0;
        que.push(s);
        while (que.size()) {
            int now = que.front();
            que.pop();
            for (auto nx : to[now]) {
                indeg[nx.first]--;
                if (dist[nx.first] > dist[now] + nx.second)
                    dist[nx.first] = dist[now] + nx.second, prev[nx.first] = now;
                if (indeg[nx.first] == 0) que.push(nx.first);
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

    void solve(int s) {
        if (wmin >= 0) {
            if (single_positive_weight) {
                ZeroOneBFS(s);
            } else {
                if ((long long)V * V < (E << 4)) {
                    DijkstraVquad(s);
                } else {
                    Dijkstra(s);
                }
            }
        } else {
            BellmanFord(s, V);
        }
    }

    // Warshall-Floyd algorithm
    // Complexity: O(E + V^3)
    std::vector<std::vector<T>> dist2d;
    void WarshallFloyd() {
        dist2d.assign(V, std::vector<T>(V, INF));
        for (int i = 0; i < V; i++) {
            dist2d[i][i] = 0;
            for (auto p : to[i]) dist2d[i][p.first] = std::min(dist2d[i][p.first], p.second);
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
    }

    void dump_graphviz(std::string filename = "shortest_path") const {
        std::ofstream ss(filename + ".DOT");
        ss << "digraph{\n";
        for (int i = 0; i < V; i++) {
            for (const auto &e : to[i]) ss << i << "->" << e.first << "[label=" << e.second << "];\n";
        }
        ss << "}\n";
        ss.close();
        return;
    }
};

#include <cassert>
#include <vector>
// (Min weight) Matroid intersection solver
// Algorithm based on http://dopal.cs.uec.ac.jp/okamotoy/lect/2015/matroid/
// Complexity: O(CE^2 + E^3) (C : circuit query, non-weighted)
template <class M1, class M2, class T = int>
std::vector<bool> MatroidIntersection(M1 matroid1, M2 matroid2, std::vector<T> weights = {}) {
    using State = std::vector<bool>;
    using Element = int;
    assert(matroid1.size() == matroid2.size());
    const int M = matroid1.size();

    for (auto &x : weights) x *= M + 1;
    if (weights.empty()) weights.assign(M, 0);

    const Element gs = M, gt = M + 1;
    State I(M);

    std::vector<T> potential(M + 2);

    while (true) {
        ShortestPath<T> sssp(M + 2);
        matroid1.set(I);
        matroid2.set(I);
        for (int e = 0; e < M; e++) {
            if (I[e]) continue;
            auto c1 = matroid1.circuit(e), c2 = matroid2.circuit(e);
            if (c1.empty()) sssp.add_edge(e, gt, weights[e]);
            for (Element f : c1) {
                if (f != e) sssp.add_edge(e, f, -weights[f] + weights[e] + 1);
            }
            if (c2.empty()) sssp.add_edge(gs, e, 0);
            for (Element f : c2) {
                if (f != e) sssp.add_edge(f, e, 0 + 1);
            }
        }
        // dbg(potential);
        // sssp.DijkstraWithPotential(gs, potential);
        sssp.solve(gs);
        auto aug_path = sssp.retrieve_path(gt);
        if (aug_path.empty()) break;
        for (auto e : aug_path) {
            if (e != gs and e != gt) I[e] = !I[e];
        }
        for (int e = 0; e < M + 2; e++) {
            if (sssp.dist[e] < 1 << 24) {
                // potential[e] = sssp.dist[e] / (M + 1) * (M + 1);
                // if (sssp.dist[e] % (M + 1) and sssp.dist[e] < 0) potential[e]--;
            }
        }
    }
    return I;
}

// Partition matroid (partitional matroid) : direct sum of uniform matroids
class PartitionMatroid {
    using Element = int;
    int M;
    std::vector<std::vector<Element>> parts;
    std::vector<int> belong;
    std::vector<int> R;
    std::vector<int> cnt;
    std::vector<std::vector<Element>> circuits;

public:
    // parts: partition of [0, 1, ..., M - 1]
    // R: only R[i] elements from parts[i] can be chosen for each i.
    PartitionMatroid(int M, const std::vector<std::vector<int>> &parts_, const std::vector<int> &R_)
        : M(M), parts(parts_), belong(M, -1), R(R_) {
        assert(parts.size() == R.size());
        for (int i = 0; i < int(parts.size()); i++) {
            for (Element e : parts[i]) belong[e] = i;
        }
        for (Element e = 0; e < M; e++) {
            // assert(belong[e] != -1);
            if (belong[e] == -1) {
                belong[e] = parts.size();
                parts.push_back({e});
                R.push_back(1);
            }
        }
    }
    int size() const { return M; }

    template <class State> void set(const State &I) {
        cnt = R;
        for (int e = 0; e < M; e++) {
            if (I[e]) cnt[belong[e]]--;
        }
        circuits.assign(cnt.size(), {});
        for (int e = 0; e < M; e++) {
            if (I[e] and cnt[belong[e]] == 0) circuits[belong[e]].push_back(e);
        }
    }

    std::vector<Element> circuit(const Element e) const {
        assert(0 <= e and e < M);
        int p = belong[e];
        if (cnt[p] == 0) {
            auto ret = circuits[p];
            ret.push_back(e);
            return ret;
        }
        return {};
    }
};

#include <numeric>
#include <utility>
#include <vector>

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

// GraphMatroid: subgraph of undirected graphs, without loops
class GraphMatroid {
    using Vertex = int;
    using Element = int;
    int M;
    int V; // # of vertices of graph
    std::vector<std::vector<std::pair<Vertex, Element>>> to;
    std::vector<std::pair<Vertex, Vertex>> edges;
    std::vector<Element> backtrack;
    std::vector<Vertex> vprev;
    std::vector<int> depth, root;

public:
    GraphMatroid(int V, std::vector<std::pair<Vertex, Vertex>> edges_)
        : M(edges_.size()), V(V), to(V), edges(edges_) {
        for (int e = 0; e < int(edges_.size()); e++) {
            assert(edges_[e].first < V and edges_[e].second < V);
            to[edges_[e].first].emplace_back(edges_[e].second, e);
            to[edges_[e].second].emplace_back(edges_[e].first, e);
        }
    }
    int size() const { return M; }

    template <class State> void set(State I) {
        assert(int(I.size()) == M);
        backtrack.assign(V, -1);
        vprev.resize(V);
        depth.assign(V, -1);
        root.resize(V);
        static std::vector<Vertex> que(V);
        int qb, qe;
        for (Vertex i = 0; i < V; i++) {
            if (backtrack[i] >= 0) continue;
            que[qb = 0] = i, qe = 1, depth[i] = 0;
            while (qb < qe) {
                Vertex now = que[qb++];
                root[now] = i;
                for (auto nxt : to[now]) {
                    if (depth[nxt.first] < 0 and I[nxt.second]) {
                        backtrack[nxt.first] = nxt.second;
                        vprev[nxt.first] = now;
                        depth[nxt.first] = depth[now] + 1;
                        que[qe++] = nxt.first;
                    }
                }
            }
        }
    }

    std::vector<Element> circuit(const Element e) const {
        assert(0 <= e and e < M);
        Vertex s = edges[e].first, t = edges[e].second;
        if (root[s] != root[t]) return {};
        std::vector<Element> ret{e};
        auto step = [&](Vertex &i) { ret.push_back(backtrack[i]), i = vprev[i]; };
        int ddepth = depth[s] - depth[t];
        for (; ddepth > 0; --ddepth) step(s);
        for (; ddepth < 0; ++ddepth) step(t);
        while (s != t) step(s), step(t);
        return ret;
    }
};


int main() {
    int N, K;
    cin >> N >> K;
    vector<int> D(K);
    cin >> D;
    vector W(N, vector<int>(N));
    REP(i, N) FOR(j, i + 1, N) {
        int w;
        cin >> w;
        W[i][j] = W[j][i] = w;
    }

    constexpr int INF = 1 << 29;
    vector<tuple<int, int, int>> special_edges;
    REP(i, K) REP(j, i) special_edges.emplace_back(W[i][j], i, j);
    vector<int> W_outer;
    vector<pint> edges_outer;

    {
        vector<tuple<int, int, int>> outer_edges;
        FOR(i, K, N) FOR(j, K, i) outer_edges.emplace_back(W[i][j], i, j);
        std::sort(outer_edges.begin(), outer_edges.end());

        // Erase useless outer_edge's
        UnionFind uf(N);
        for (auto [w, u, v] : outer_edges) {
            if (uf.unite(u, v)) {
                W_outer.push_back(w);
                edges_outer.emplace_back(u, v);
            }
        }
    }

    int ret = INF;
    for (int s = 0; s < (1 << special_edges.size()); s++) {
        int wnow = 0;
        UnionFind uf(N);
        auto deg_upper = D;
        for (int se = 0; se < int(special_edges.size()); se++) {
            auto [w, u, v] = special_edges[se];
            if ((s >> se) & 1 and uf.unite(u, v)) wnow += w, deg_upper[u]--, deg_upper[v]--;
        }
        if (*min_element(ALL(deg_upper)) < 0) continue;

        vector<int> ws = W_outer;
        vector<pair<int, int>> edges = edges_outer;
        vector<vector<int>> partitions(K);
        REP(i, K) FOR(j, K, N) {
            if (!deg_upper[i]) continue;
            int eid = ws.size();
            ws.push_back(W[i][j]);
            edges.emplace_back(uf.find(i), j);
            partitions[i].push_back(eid);
        }
        GraphMatroid mat1(N, edges);
        PartitionMatroid mat2(edges.size(), partitions, deg_upper);
        auto sol = MatroidIntersection(mat1, mat2, ws);
        auto deg_upper_origin = deg_upper;
        REP(e, sol.size()) if (sol[e]) {
            uf.unite(edges[e].first, edges[e].second);
            if (edges[e].first < K) deg_upper[edges[e].first]--;
            wnow += ws[e];
        }
        if (uf.count(0) == N) chmin(ret, wnow);
    }
    cout << ret << '\n';
}