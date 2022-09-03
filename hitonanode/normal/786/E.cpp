#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

template<typename T>
struct Maxflow
{
    struct edge { int to; T cap; int rev; };
    std::vector<std::vector<edge>> edges;
    std::vector<int> level;
    std::vector<int> iter;
    std::vector<int> used;
    std::vector<int> reachable;

    void bfs(int s)
    {
        level.assign(edges.size(), -1);
        std::queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (edge &e : edges[v]) {
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }
 
    T dfs_d(int v, int goal, T f)
    {
        if (v == goal) return f;
        for (int &i = iter[v]; i < (int)edges[v].size(); i++) {
            edge &e = edges[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                T d = dfs_d(e.to, goal, std::min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    edges[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
 
    T dfs_ff(int v, int goal, T f)
    {
        if (v == goal) return f;
        used[v] = true;
        for (int i = 0; i < (int)edges[v].size(); i++)
        {
            edge &e = edges[v][i];
            if (e.cap > 0 && !used[e.to])
            {
                T d = dfs_ff(e.to, goal, std::min(f, e.cap));
                if (d > 0)
                {
                    e.cap -= d;
                    edges[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
 
public:
    Maxflow(int N) { edges.resize(N); }
    void add_edge(int from, int to, T capacity)
    {
        edges[from].push_back(edge{to, capacity, (int)edges[to].size()});
        edges[to].push_back(edge{from, (T)0, (int)edges[from].size() - 1});
    }
 
    T Dinic(int s, int t)
    {
        constexpr T INF = std::numeric_limits<T>::max();
        T flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;
            iter.assign(edges.size(), 0);
            T f;
            while ((f = dfs_d(s, t, INF)) > 0) flow += f;
        }
    }
 
    T FF(int s, int t)
    {
        constexpr T INF = std::numeric_limits<T>::max();
        T flow = 0;
        while (true) {
            used.assign(edges.size(), 0);
            T f = dfs_ff(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }
 
    void back_flow(int s, int t, int s_e, int t_e, T capacity_reduce)
    {
        int i;
        for (i=0; edges[s_e][i].to != t_e; ) i++;
        edge &e = edges[s_e][i];
 
        if (capacity_reduce <= e.cap) {
            e.cap -= capacity_reduce;
        }
        else {
            T flow = capacity_reduce - e.cap;
            e.cap = 0;
            edges[e.to][e.rev].cap -= flow;
 
            T f_sum = 0;
            while (f_sum != flow) {
                used.assign(edges.size(), 0);
                f_sum += dfs_ff(t, t_e, flow - f_sum);
            }
            f_sum = 0;
            while (f_sum != flow) {
                used.assign(edges.size(), 0);
                f_sum += dfs_ff(s_e, s, flow - f_sum);
            }
        }
    }
};

#include <bits/stdc++.h>
using namespace std;
struct UndirectedWeightedTree
{
    using T = long long int;   // Arbitrary data structure (operator+, operator- must be defined)
    const int INVALID = -1;
    int V, lgV;
    int E;
    int root;
    vector<vector<pair<int, int>>> adj; // (nxt_vertex, edge_id)
    // vector<pint> edge;  // edges[edge_id] = (vertex_id, vertex_id)
    vector<T> weight;  // w[edge_id]
    vector<int> par;  // parent_vertex_id[vertex_id]
    vector<int> depth;  // depth_from_root[vertex_id]
    vector<T> acc_weight;  // w_sum_from_root[vertex_id]
 
    void _fix_root_dfs(int now, int prv, int prv_edge_id)
    {
        par[now] = prv;
        if (prv_edge_id != INVALID) acc_weight[now] = acc_weight[prv] + weight[prv_edge_id];
        for (auto nxt : adj[now]) if (nxt.first != prv)
        {
            depth[nxt.first] = depth[now] + 1;
            _fix_root_dfs(nxt.first, now, nxt.second);
        }
    }
 
public:
    UndirectedWeightedTree(int N = 0): V(N), E(0), adj(N) {
        lgV = 1;
        while (1 << lgV < V) lgV++;
    }
 
    void add_edge(int u, int v, T w)
    {
        adj[u].emplace_back(v, E);
        adj[v].emplace_back(u, E);
        // edge.emplace_back(u, v);
        weight.emplace_back(w);
        E++;
    }
 
    void fix_root(int r)
    {
        root = r;
        par.resize(V);
        depth.assign(V, 0);
        acc_weight.resize(V);
        _fix_root_dfs(root, INVALID, INVALID);
    }
 
    vector<vector<int>> doubling;
    void doubling_precalc()
    {
        doubling.assign(lgV, vector<int>(V));
        doubling[0] = par;
        for (int d = 0; d < lgV - 1; d++) for (int i = 0; i < V; i++)
        {
            if (doubling[d][i] == INVALID) doubling[d + 1][i] = INVALID;
            else doubling[d + 1][i] = doubling[d][doubling[d][i]];
        }
    }
 
    int kth_parent(int x, int k)
    {
        for (int d = 0; d < lgV; d++)
        {
            if (x == INVALID) return INVALID;
            if (k & (1 << d)) x = doubling[d][x];
        }
        return x;
    }
 
    int lowest_common_ancestor(int u, int v)
    {
        if (depth[u] > depth[v]) std::swap(u, v);
 
        v = kth_parent(v, depth[v] - depth[u]);
        if (u == v) return u;
        for (int d = lgV - 1; d >= 0; d--)
        {
            if (doubling[d][u] != doubling[d][v]) u = doubling[d][u], v = doubling[d][v];
        }
        return par[u];
    }
 
    T path_length(int u, int v)
    {
        // Not distance, but the sum of weights
        int r = lowest_common_ancestor(u, v);
        return (acc_weight[u] - acc_weight[r]) + (acc_weight[v] - acc_weight[r]);
    }
};

#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    UndirectedWeightedTree tree(N);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v) swap(u, v);
        mp[make_pair(u, v)] = i;
        tree.add_edge(u, v, 1);
    }
    tree.fix_root(0);
    tree.doubling_precalc();
    
    int D = tree.lgV;
    int T = 1 + M + N * D;
    Maxflow<int> mf(T + 1);
    REP(i, N) {
        FOR(d, 1, D) {
            int nx = tree.doubling[d - 1][i];
            if (nx >= 0) {
                mf.add_edge(1 + M + i * D + d, 1 + M + i * D + d - 1, 1e7);
                mf.add_edge(1 + M + i * D + d, 1 + M + nx * D + d - 1, 1e7);
            }
        }
        if (i) mf.add_edge(1 + M + i * D, T, 1);
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int r = tree.lowest_common_ancestor(x, y);
        mf.add_edge(0, i + 1, 1);
        REP(_, 2) {
            int dis = tree.path_length(r, x);
            REP(d, D) if ((dis >> d) & 1) {
                mf.add_edge(i + 1, 1 + M + x * D + d, 1e7);
                x = tree.doubling[d][x];
            }
            swap(x, y);
        }
    }
    int k = mf.Dinic(0, T);
    printf("%d\n", k);

    // mf.cut_dfs(0);
    vector<int> ret_c;
    vector<int> ret_g;
    REP(i, M) if (mf.level[i + 1] < 0) ret_c.push_back(i + 1);
    printf("%d", (int)ret_c.size());
    for (auto x : ret_c) printf(" %d", x);
    puts("");
    FOR(i, 1, N) if (mf.level[1 + M + i * D] >= 0) ret_g.emplace_back(i);
    printf("%d", (int)ret_g.size());
    for (auto x : ret_g) {
        int y = tree.par[x];
        printf(" %d", mp[minmax(x, y)] + 1);
    }
    puts("");
}