#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to, cost, capacity;
    Edge(int from=-1, int to=-1, int cost=0, int capacity=0)
        : from(from), to(to), cost(cost), capacity(capacity) {
    }
};

std::pair<bool, std::vector<int>> BellmanFord(std::vector<Edge> const& edges, int s, int n) {
    int INF = std::numeric_limits<int>::max();
    std::vector<int> d(n, INF);
    d[s] = 0;

    bool improved = true;
    for (int i = 0; i < n && improved; ++i) {
        improved = false;
        for (Edge const& e : edges) {
            if (e.capacity > 0 && d[e.from] < INF && d[e.from] + e.cost < d[e.to]) {
                d[e.to] = d[e.from] + e.cost;
                improved = true;
            }
        }
    }
    return {improved, d};  // true if negative cycle
}

class MinCostMaxFlow {
public:
    std::pair<int, int> solve(std::vector<Edge> const& edges, int source, int sink, int n) {
        int m = (int)edges.size();
        directed_edges.resize(2 * m);
        adj.resize(n);
        for (int i = 0; i < m; i++) {
            Edge e = edges[i];
            directed_edges[2*i] = e;
            directed_edges[2*i+1] = Edge(e.to, e.from, -e.cost, 0);
            adj[e.from].push_back(2*i);
            adj[e.to].push_back(2*i+1);
        }

        auto [negative_cycle, distances] = BellmanFord(directed_edges, source, n);
        assert(!negative_cycle);
        potential = distances;

        int flow = 0;
        int total_cost = 0;
        while (true) {
            auto [distances, prev_edge] = dijkstra(source);
            if (prev_edge[sink] == -1)
                break;

            // fix potentials
            for (int i = 0; i < n; i++) {
                if (distances[i] < std::numeric_limits<int>::max())
                    potential[i] += distances[i];
            }

            // augment path
            int cur_flow = std::numeric_limits<int>::max();
            int cur = sink;
            while (cur != source) {
                int prev_edge_idx = prev_edge[cur];
                Edge& prev_edge = directed_edges[prev_edge_idx];
                cur_flow = std::min(cur_flow, prev_edge.capacity);
                cur = prev_edge.from;
            }
            cur = sink;
            flow += cur_flow;
            while (cur != source) {
                int prev_edge_idx = prev_edge[cur];
                Edge& prev_edge = directed_edges[prev_edge_idx];
                Edge& prev_edge_rev = directed_edges[prev_edge_idx ^ 1];
                total_cost += cur_flow * prev_edge.cost;
                prev_edge.capacity -= cur_flow;
                prev_edge_rev.capacity += cur_flow;
                cur = prev_edge.from;
            }
        }

        return {flow, total_cost};
    }

    std::pair<std::vector<int>, std::vector<int>> dijkstra(int v0) {
        int n = adj.size();
        int INF = std::numeric_limits<int>::max();
        std::vector<int> distance(n, INF), prev_edge(n, -1);
        std::priority_queue<std::pair<int, int>> pq;
        pq.push({0, v0});
        distance[v0] = 0;
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            long long dist = -x.first;
            int v = x.second;
            if (dist > distance[v])
                continue;
            for (auto e_idx : adj[v]) {
                Edge& e = directed_edges[e_idx];
                if (e.capacity == 0)
                    continue;
                int new_cost = e.cost + potential[v]- potential[e.to];
                if (dist + new_cost < distance[e.to]) {
                    distance[e.to] = dist + new_cost;
                    prev_edge[e.to] = e_idx;
                    pq.push({-distance[e.to], e.to});
                }
            }
        }
        return {distance, prev_edge};
    }

private:
    std::vector<int> potential;
    std::vector<std::vector<int>> adj;
    std::vector<Edge> directed_edges;
};

int n;
vector<Edge> edges;
int INF = std::numeric_limits<int>::max();

int dfs(vector<vector<int>> const& adj, vector<int> const& demands, int v, int p, bool forward) {
    int cur = demands[v];
    int children = 0;
    for (int u : adj[v]) {
        if (u == p)
            continue;

        if (demands[u] == 0) {
            if (forward)
                edges.emplace_back(v, u, 0, INF);
            else
                edges.emplace_back(u+n, v+n, 0, INF);
        }
        children += dfs(adj, demands, u, v, forward);
    }

    if (cur > 0) {
        if (cur >= children) {
            if (cur > children) {
                if (forward)
                    edges.emplace_back(2*n, v, 0, cur - children);
                else
                    edges.emplace_back(n+v, 2*n+1, 0, cur - children);
            }
        } else {
            cout << -1 << '\n';
            exit(0);
        }
        return cur;
    }

    return children;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> n >> x >> y;
    x--;
    y--;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    
    vector<vector<int>> adj;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> adj2;
    adj2.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    
    vector<int> demands1(n, 0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int j, c;
        cin >> j >> c;
        demands1[j-1] = c;
    }
    vector<int> demands2(n, 0);
    cin >> q;
    for (int i = 0; i < q; i++) {
        int j, c;
        cin >> j >> c;
        demands2[j-1] = c;
    }

    for (int i = 0; i < n; i++) {
        edges.emplace_back(i, i+n, -a[i], 1);
    }

    int sum1 = dfs(adj, demands1, x, -1, true);
    int sum2 = dfs(adj2, demands2, y, -1, false);

    if (sum1 != sum2) {
        cout << -1 << '\n';
        exit(0);
    }

    auto [flow, total_cost] = MinCostMaxFlow().solve(edges, 2*n, 2*n+1, 2*n+2);
    if (flow != sum1) {
        cout << -1 << '\n';
        exit(0);
    }

    cout << -total_cost << '\n';
}