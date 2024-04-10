#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

template<typename T>
struct ShortestPath
{
    int V, E;
    int INVALID = -1;
    std::vector<std::vector<std::pair<int, T>>> to;
    ShortestPath() = default;
    ShortestPath(int V) : V(V), E(0), to(V) {}
    void add_edge(int s, int t, T len) {
        assert(0 <= s and s < V);
        assert(0 <= t and t < V);
        to[s].emplace_back(t, len);
        E++;
    }

    std::vector<T> dist;
    std::vector<int> prev;
    // Dijkstra algorithm
    // Complexity: O(E log E)
    void Dijkstra(int s) {
        assert(0 <= s and s < V);
        dist.assign(V, std::numeric_limits<T>::max());
        dist[s] = 0;
        prev.assign(V, INVALID);
        using P = std::pair<T, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
        pq.emplace(0, s);
        while(!pq.empty()) {
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
};
int main()
{
    int N, M;
    cin >> N >> M;
    vector to(N, vector<int>(N));
    while (M--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        to[u][v] = to[v][u] = 1;
    }
    if (to[0][N - 1])
    {
        REP(i, N) REP(j, N) if (i != j) to[i][j] ^= 1;
    }
    ShortestPath<int> graph(N);
    REP(i, N) REP(j, N) if (to[i][j]) graph.add_edge(i, j, 1);
    graph.Dijkstra(0);
    int ret = graph.dist[N - 1];
    cout << (ret < 1e5 ? ret : -1) << '\n';
}