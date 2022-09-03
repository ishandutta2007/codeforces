#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

// Directed graph library to find strongly connected components 
// 0-indexed directed graph
// Complexity: O(V + E)
struct DirectedGraphSCC {
    int V; // # of Vertices
    std::vector<std::vector<int>> to, from;
    std::vector<int> used;  // Only true/false
    std::vector<int> vs;
    std::vector<int> cmp;
    int scc_num = -1;

    DirectedGraphSCC(int V = 0) : V(V), to(V), from(V), cmp(V) {}

    void _dfs(int v) {
        used[v] = true;
        for (auto t : to[v]) if (!used[t]) _dfs(t);
        vs.push_back(v);
    }
    void _rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for (auto t : from[v]) if (!used[t]) _rdfs(t, k);
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
        for (int v = 0; v < V; v++) if (!used[v]) _dfs(v);
        used.assign(V, false);
        scc_num = 0;
        for (int i = (int)vs.size() - 1; i >= 0; i--) if (!used[vs[i]]) _rdfs(vs[i], scc_num++);
        return scc_num;
    }

    // After calling `FindStronglyConnectedComponents()`, generate a new graph by uniting all vertices
    // belonging to the same component(The resultant graph is DAG).
    DirectedGraphSCC GenerateTopologicalGraph() {
        DirectedGraphSCC newgraph(scc_num);
        for (int s = 0; s < V; s++) for (auto t : to[s]) {
            if (cmp[s] != cmp[t]) newgraph.add_edge(cmp[s], cmp[t]);
        }
        return newgraph;
    }
};


int main()
{
    int N, M;
    cin >> N >> M;
    DirectedGraphSCC graph(N);
    REP(i, M)
    {
        int j, k;
        cin >> j >> k;
        j--, k--;
        graph.add_edge(j, k);
    }
    graph.FindStronglyConnectedComponents();
    if (graph.scc_num != N)
    {
        puts("-1");
        return 0;
    }
    string ret(N, 'E');
    int cnt = 0;
    vector<int> visited_to(N), visited_from(N);
    auto dfs_to = [&](auto &&f, int now) -> void
    {
        visited_to[now] = 1;
        for (auto nxt : graph.to[now]) if (!visited_to[nxt]) f(f, nxt);
    };
    auto dfs_from = [&](auto &&f, int now) -> void
    {
        visited_from[now] = 1;
        for (auto nxt : graph.from[now]) if (!visited_from[nxt]) f(f, nxt);
    };
    REP(i, N)
    {
        if (!visited_to[i] and !visited_from[i]) ret[i] = 'A';
        if (!visited_to[i]) dfs_to(dfs_to, i);
        if (!visited_from[i]) dfs_from(dfs_from, i);
    }
    for (auto c : ret) cnt += (c == 'A');
    cout << cnt << '\n' << ret << '\n';
}