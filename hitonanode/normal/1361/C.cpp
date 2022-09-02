#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
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


// <https://ei1333.github.io/luzhiled/snippets/graph/eulerian-trail.html>
template <typename T>
struct edge
{
    int src, to, id_;
    T cost;

    edge() = default;
    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost, int id_) : src(src), to(to), cost(cost), id_(id_) {}

    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};
template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
vector<edge<T>> eulerian_path(Edges<T> es, int s, bool directed)
{
    int V = 0;
    for (auto &e : es)
        V = max(V, max(e.to, e.src) + 1);
    vector<vector<pair<edge<T>, int>>> g(V);
    for (auto &e : es)
    {
        int sz_to = (int)g[e.to].size();
        g[e.src].emplace_back(e, sz_to);
        if (!directed)
        {
            int sz_src = (int)g[e.src].size() - 1;
            swap(e.src, e.to);
            g[e.src].emplace_back(e, sz_src);
        }
    }
    vector<edge<T>> ord;
    stack<pair<int, edge<T>>> st;
    st.emplace(s, edge<T>(-1, -1));
    while (st.size())
    {
        int idx = st.top().first;
        if (g[idx].empty())
        {
            ord.emplace_back(st.top().second);
            st.pop();
        }
        else
        {
            auto e = g[idx].back();
            g[idx].pop_back();
            if (e.second == -1)
                continue;
            if (!directed)
                g[e.first.to][e.second].second = -1;
            st.emplace(e.first.to, e.first);
        }
    }
    ord.pop_back();
    reverse(begin(ord), end(ord));
    if (ord.size() != es.size())
        return {};
    return ord;
}

// This implementation is based on https://ei1333.github.io/library/graph/others/eulerian-trail.cpp
template <bool directed> struct EulerianTrail {
    using Vertex = int;
    using Edge = int;
    int M;
    std::vector<int> deg;
    std::vector<std::pair<Vertex, Vertex>> edges;
    std::vector<std::vector<std::pair<Vertex, Edge>>> to;
    std::vector<int> used_vertex, used_edge;
    EulerianTrail(int V = 0) : M(0), deg(V, 0), to(V), used_vertex(V) {}
    void add_edge(Vertex a, Vertex b) {
        to[a].emplace_back(b, M);
        if (directed) {
            deg[a]++;
            deg[b]--;
        } else {
            to[b].emplace_back(a, M);
            deg[a]++;
            deg[b]++;
        }
        edges.emplace_back(a, b);
        M++;
        used_edge.push_back(0);
    }

    std::vector<std::vector<Edge>> solve() {
        if (directed) {
            if (std::count_if(deg.begin(), deg.end(), [](int x) { return x != 0; })) return {};
        } else {
            if (std::count_if(deg.begin(), deg.end(), [](int x) { return (x & 1) != 0; })) return {};
        }
        std::vector<std::vector<Edge>> ret;
        for (int i = 0; i < int(to.size()); i++) {
            if (to[i].empty() or used_vertex[i]) continue;
            ret.emplace_back(go(i));
        }
        return ret;
    }

    std::vector<Edge> go(Vertex s) {
        std::vector<std::pair<Vertex, Edge>> st;
        std::vector<Edge> ord;
        st.emplace_back(s, -1);
        while (!st.empty()) {
            Vertex now = st.back().first;
            used_vertex[now] = true;
            if (to[now].empty()) {
                ord.emplace_back(st.back().second);
                st.pop_back();
            } else {
                auto e = to[now].back();
                to[now].pop_back();
                if (used_edge[e.second]) continue;
                used_edge[e.second] = true;
                st.emplace_back(e);
            }
        }
        ord.pop_back();
        std::reverse(ord.begin(), ord.end());
        return ord;
    }
};

int N;
vector<int> P;

bool solve(int d)
{
    UnionFind uf(1 << d);
    vector<int> cnt(1 << d);
    map<int, queue<int>> loops;
    map<int, queue<int>> to;
    int window = (1 << d) - 1;
    REP(i, N)
    {
        int v0 = P[i * 2 + 0] & window;
        int v1 = P[i * 2 + 1] & window;
        uf.unite(v0, v1);
        cnt[v0]++;
        cnt[v1]++;
    }

    {
        REP(i, cnt.size()) if (cnt[i] % 2) return false;
        int a = P[0] & window;
        REP(i, P.size()) if (!uf.same(a, P[i] & window)) return false;
    }

    // Edges<int> edges(N);
    // REP(i, N)
    // {
    //     int v0 = P[i * 2 + 0] & window;
    //     int v1 = P[i * 2 + 1] & window;
    //     edges[i] = edge<int>(v0, v1, 0, i);
    // }


    cout << d << '\n';
    int n = P[0] & window;
    EulerianTrail<false> graph(1 << d);
    REP(i, N) {
        int v0 = P[i * 2 + 0] & window;
        int v1 = P[i * 2 + 1] & window;
        graph.add_edge(v0, v1);
    }
    auto ret = graph.go(n);
    for (auto e : ret)
    {
        // int e = ed.id_;
        // int a = P[e * 2 + 0] & window;
        // int b = P[e * 2 + 1] & window;
        auto [a, b] = graph.edges[e];
        if (a == n) {
            cout << e * 2 + 1 << ' ' << e * 2 + 2 << ' ';
            n = b;
        } else {
            cout << e * 2 + 2 << ' ' << e * 2 + 1 << ' ';
            n = a;
        }
    }
    cout << '\n';
    return true;
}

int main()
{
    cin >> N;
    P.resize(N * 2);
    cin >> P;
    IREP(d, 21)
    {
        if (solve(d)) break;
    }
}