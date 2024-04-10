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
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
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
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif

struct UndirectedGraph
{
    int V; // # of vertices
    int E; // # of edges
    int k;
    std::vector<std::vector<std::pair<int, int>>> to;
    std::vector<std::pair<int, int>> edges;
    std::vector<int> root_ids; // DFS forest

    std::vector<int> is_bridge; // Whether edge i is bridge or not, size = E
    std::vector<int> is_articulation; // whether vertex i is articulation point or not, size = V

    // lowlink
    std::vector<int> order;   // visiting order of DFS tree, size = V
    std::vector<int> lowlink; // size = V
    std::vector<int> is_dfstree_edge; // size = E

    int tecc_num; // 
    std::vector<int> tecc_id; // 

    int tvcc_num; // 
    std::vector<int> tvcc_id; // 

    UndirectedGraph(int V) : V(V), E(0), k(0), to(V), is_articulation(V, 0), order(V, -1), lowlink(V, -1), tecc_num(0), tvcc_num(0) {}

    void add_edge(int v1, int v2)
    {
        assert(v1 >= 0 and v1 < V);
        assert(v2 >= 0 and v2 < V);
        to[v1].emplace_back(v2, E);
        to[v2].emplace_back(v1, E);
        edges.emplace_back(v1, v2);
        is_bridge.push_back(0);
        is_dfstree_edge.push_back(0);
        tvcc_id.push_back(-1);
        E++;
    }

    std::vector<int> _edge_stack;
    int _root_now;

    // Build DFS tree
    // Complexity: O(V + E)
    void dfs_lowlink(int now, int prv_eid = -1)
    {
        if (prv_eid < 0) _root_now = k;
        if (prv_eid == -1) root_ids.push_back(now);
        order[now] = lowlink[now] = k++;
        for (const auto &nxt : to[now]) if (nxt.second != prv_eid)
        {
            if (order[nxt.first] < order[now]) _edge_stack.push_back(nxt.second);
            if (order[nxt.first] >= 0)
            {
                lowlink[now] = std::min(lowlink[now], order[nxt.first]);
            }
            else
            {
                is_dfstree_edge[nxt.second] = 1;
                dfs_lowlink(nxt.first, nxt.second);
                lowlink[now] = std::min(lowlink[now], lowlink[nxt.first]);

                if ((order[now] == _root_now and order[nxt.first] != _root_now + 1) or (order[now] != _root_now and lowlink[nxt.first] >= order[now])) {
                    is_articulation[now] = 1;
                }
                if (lowlink[nxt.first] >= order[now]) {
                    while (true) {
                        int e = _edge_stack.back();
                        tvcc_id[e] = tvcc_num;
                        _edge_stack.pop_back();
                        if (std::minmax(edges[e].first, edges[e].second) == std::minmax(now, nxt.first)) {
                            break;
                        }
                    }
                    tvcc_num++;
                }
            }
        }
    }

    // Find all bridges
    // Complexity: O(V + E)
    void detectBridge()
    {
        for (int i = 0; i < E; i++)
        {
            int v1 = edges[i].first, v2 = edges[i].second;
            if (order[v1] < 0) dfs_lowlink(v1);
            if (order[v1] > order[v2]) std::swap(v1, v2);
            if (order[v1] < lowlink[v2]) is_bridge[i] = 1;
        }
    }

    // Find two-edge-connected components and classify all vertices
    // Complexity:  O(V + E)
    int two_edge_connected_components()
    {
        tecc_num = 0;
        tecc_id.assign(V, -1);

        for (int i = 0; i < V; i++) if (tecc_id[i] == -1)
        {
            tecc_id[i] = tecc_num;
            std::queue<int> que;
            que.push(i);
            while (!que.empty())
            {
                int now = que.front();
                que.pop();
                for (const auto &edge : to[now])
                {
                    int nxt = edge.first;
                    if (tecc_id[nxt] >= 0 or is_bridge[edge.second]) continue;
                    tecc_id[nxt] = tecc_num;
                    que.push(nxt);
                }
            }
            tecc_num++;
        }
        return tecc_num;
    }
};
// Heavy-Light Decomposition of trees
// Based on <http://beet-aizu.hatenablog.com/entry/2017/12/12/235950>
struct HeavyLightDecomposition {
    int V;
    int k;
    int nb_heavy_path;
    std::vector<std::vector<int>> e;
    std::vector<int> par;  // par[i] = parent of vertex i (Default: -1)
    std::vector<int> depth;  // depth[i] = distance between root and vertex i
    std::vector<int> subtree_sz; // subtree_sz[i] = size of subtree whose root is i
    std::vector<int> heavy_child;  // heavy_child[i] = child of vertex i on heavy path (Default: -1)
    std::vector<int> tree_id;  // tree_id[i] = id of tree vertex i belongs to
    std::vector<int> aligned_id, aligned_id_inv;  // aligned_id[i] =  aligned id for vertex i (consecutive on heavy edges)
    std::vector<int> head;  // head[i] = id of vertex on heavy path of vertex i, nearest to root
    std::vector<int> head_ids;  // consist of head vertex id's
    std::vector<int> heavy_path_id;  // heavy_path_id[i] = heavy_path_id for vertex [i]

    HeavyLightDecomposition(int sz = 0) : V(sz), k(0), nb_heavy_path(0), e(sz), par(sz), depth(sz),
    subtree_sz(sz), heavy_child(sz), tree_id(sz, -1), aligned_id(sz), aligned_id_inv(sz), head(sz), heavy_path_id(sz, -1) {}
    void add_edge(int u, int v) {
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    void _build_dfs(int root) {
        std::stack<std::pair<int, int>> st;
        par[root] = -1;
        depth[root] = 0;
        st.emplace(root, 0);
        while (!st.empty()) {
            int now = st.top().first;
            int &i = st.top().second;
            if (i < (int)e[now].size()) {
                int nxt = e[now][i++];
                if (nxt == par[now]) continue;
                par[nxt] = now;
                depth[nxt] = depth[now] + 1;
                st.emplace(nxt, 0);
            } else {
                st.pop();
                int max_sub_sz = 0;
                subtree_sz[now] = 1;
                heavy_child[now] = -1;
                for (auto nxt : e[now]) {
                    if (nxt == par[now]) continue;
                    subtree_sz[now] += subtree_sz[nxt];
                    if (max_sub_sz < subtree_sz[nxt]) max_sub_sz = subtree_sz[nxt], heavy_child[now] = nxt;
                }
            }
        }
    }

    void _build_bfs(int root, int tree_id_now) {
        std::queue<int> q({root});
        while (!q.empty()) {
            int h = q.front();
            q.pop();
            head_ids.emplace_back(h);
            for (int now = h; now != -1; now = heavy_child[now]) {
                tree_id[now] = tree_id_now;
                aligned_id[now] = k++;
                aligned_id_inv[aligned_id[now]] = now;
                heavy_path_id[now] = nb_heavy_path;
                head[now] = h;
                for (int nxt : e[now]) if (nxt != par[now] and nxt != heavy_child[now]) q.push(nxt);
            }
            nb_heavy_path++;
        }
    }

    void build(std::vector<int> roots = {0}) {
        int tree_id_now = 0;
        for (auto r : roots) {
            _build_dfs(r);
            _build_bfs(r, tree_id_now++);
        }
    }

    // query for vertices on path [u, v] (INCLUSIVE)
    void for_each_vertex(int u, int v, const std::function<void(int, int)>& f) {
        while (true) {
            if (aligned_id[u] > aligned_id[v]) std::swap(u, v);
            f(std::max(aligned_id[head[v]], aligned_id[u]), aligned_id[v]);
            if (head[u] != head[v]) v = par[head[v]];
            else break;
        }
    }

    // query for edges on path [u, v]
    void for_each_edge(int u, int v, const std::function<void(int, int)>& f)
    {
        while (true) {
            if (aligned_id[u] > aligned_id[v]) std::swap(u, v);
            if (head[u] != head[v]) {
                f(aligned_id[head[v]], aligned_id[v]);
                v = par[head[v]];
            }
            else {
                if (u != v) f(aligned_id[u] + 1, aligned_id[v]);
                break;
            }
        }
    }

    // lowest_common_ancestor: O(logV)
    int lowest_common_ancestor(int u, int v) {
        assert(tree_id[u] == tree_id[v] and tree_id[u] >= 0);
        while (true) {
            if (aligned_id[u] > aligned_id[v]) std::swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }

    int distance(int u, int v) {
        assert(tree_id[u] == tree_id[v] and tree_id[u] >= 0);
        return depth[u] + depth[v] - 2 * depth[lowest_common_ancestor(u, v)];
    }
};
// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind
{
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) {
        iota(par.begin(), par.end(), 0);
    }
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

void BAD()
{
    puts("No");
    exit(0);
}

// StarrySkyTree: segment tree for Range Minimum Query & Range Add Query
// Complexity: O(N) (construction), O(lg N) (add / get)
template <typename Tp>
struct RangeAddRangeMin
{
    int N, head;
    Tp defaultMin;
    std::vector<Tp> range_min, range_add;
    static inline Tp f(Tp x, Tp y) noexcept
    {
        return std::min(x, y);
    }

    inline void _merge(int pos)
    {
        range_min[pos] = f(range_min[pos * 2] + range_add[pos * 2], range_min[pos * 2 + 1] + range_add[pos * 2 + 1]);
    }
    void initialize(const std::vector<Tp> &data_init, Tp default_min)
    {
        N = data_init.size(), head = 1;
        while (head < N) head <<= 1;
        defaultMin = default_min;
        range_min.assign(head * 2, defaultMin);
        range_add.assign(head * 2, 0);
        std::copy(data_init.begin(), data_init.end(), range_min.begin() + head);
        for (int pos = head; --pos;) _merge(pos);
    }
    RangeAddRangeMin() = default;
    RangeAddRangeMin(const std::vector<Tp> &data_init, Tp default_min)
    {
        initialize(data_init, default_min);
    }
    void _add(int begin, int end, int pos, int l, int r, Tp vadd) noexcept
    {
        if (r <= begin or end <= l) return;
        if (begin <= l and r <= end)
        {
            range_add[pos] += vadd;
            return;
        }
        _add(begin, end, pos * 2, l, (l + r) / 2, vadd);
        _add(begin, end, pos * 2 + 1, (l + r) / 2, r, vadd);
        _merge(pos);
    }
    // Add `vadd` to (x_begin, ..., x_{end - 1})
    void add(int begin, int end, Tp vadd) noexcept
    {
        return _add(begin, end, 1, 0, head, vadd);
    }
    Tp _get(int begin, int end, int pos, int l, int r) const noexcept
    {
        if (r <= begin or end <= l) return defaultMin;
        if (begin <= l and r <= end) return range_min[pos] + range_add[pos];
        return f(_get(begin, end, pos * 2, l, (l + r) / 2), _get(begin, end, pos * 2 + 1, (l + r) / 2, r)) + range_add[pos];
    }
    // Return f(x_begin, ..., x_{end - 1})
    Tp get(int begin, int end) const noexcept
    {
        return _get(begin, end, 1, 0, head);
    }
};

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    UndirectedGraph graph(N);
    while (M--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph.add_edge(a, b);
    }
    graph.detectBridge();
    int V = graph.two_edge_connected_components();
    dbg(V);
    dbg(graph.tecc_id);
    vector<vector<int>> to(V);
    HeavyLightDecomposition hl(V);
    UnionFind uf(V);
    for (auto [a, b] : graph.edges) {
        a = graph.tecc_id[a], b = graph.tecc_id[b];
        if (a != b) {
            hl.add_edge(a, b);
            uf.unite(a, b);
            to[a].emplace_back(b), to[b].emplace_back(a);
        }
    }
    dbg(to);

    vector<int> roots;
    REP(i, V) roots.emplace_back(uf.find(i));
    roots = srtunq(roots);

    hl.build(roots);

    RangeAddRangeMin<lint> rq(vector<lint>(V, 0), 1LL << 60);
    while (Q--) {
        int s, d;
        cin >> s >> d;
        s--, d--;
        s = graph.tecc_id[s], d = graph.tecc_id[d];
        if (!uf.same(s, d)) BAD();
        int l = hl.lowest_common_ancestor(s, d);
        dbg((vector<int>{s, d, l}));;
        hl.for_each_edge(l, s, [&](int x, int y) { rq.add(x, y + 1, 1LL); });
        hl.for_each_edge(l, d, [&](int x, int y) { rq.add(x, y + 1, 1LL << 32); });
    }
    REP(i, V) {
        lint t = rq.get(i, i + 1);
        dbg(t);
        dbg((bitset<64>(t)));
        if (t % (1 << 30) and t >> 32) {
            BAD();
        }
    }
    puts("Yes");
}