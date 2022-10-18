#include <bits/stdc++.h>
using namespace std;

class EdmondKarp
{
public:
    EdmondKarp(int n)
        : n(n) {
            capacity.assign(n, vector<int>(n, 0));
    }
 
    void determine_adj() {
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (capacity[i][j] || capacity[j][i])
                    adj[i].push_back(j);
            }
        }
    }

    int maxflow(int s, int t) {
        int flow = 0;
        std::vector<int> parent(n);
        int new_flow;
        while ((new_flow = bfs(s, t, parent))) {
            flow += new_flow;
            int node = t;
            while (node != s) {
                int prev = parent[node];
                capacity[prev][node] -= new_flow;
                capacity[node][prev] += new_flow;
                node = prev;
            }
        }
        return flow;
    }
 
    int bfs(int s, int t, std::vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        std::queue<std::pair<int, int>> q;
        q.push({s, std::numeric_limits<int>::max()});
 
        while (!q.empty()) {
            int node, flow;
            std::tie(node, flow) = q.front();
            q.pop();
 
            for (auto next : adj[node]) {
                if (parent[next] == -1 && capacity[node][next]) {
                    parent[next] = node;
                    int new_flow = std::min(flow, capacity[node][next]);
                    if (next == t)
                        return new_flow;
                    q.push({next, new_flow});
                }
            }
        }
 
        return 0;
    }
 
    int n;
    std::vector<std::vector<int>> capacity;
    std::vector<std::vector<int>> adj;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    int n = n1 + n2 + 4;
    vector<pair<int, int>> edges(m);
    vector<int> degree(n1 + n2, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        v += n1;
        edges[i] = {u, v};
        degree[u]++;
        degree[v]++;
    }

    int minDegree = m;
    for (int x : degree)
        minDegree = min(minDegree, x);

    EdmondKarp ek(n);
    auto fill_capacity = [&](int deg) {
        auto& capacity = ek.capacity;
        for (auto& e : edges) {
            capacity[e.first][e.second] = 0;
            capacity[e.second][e.first] = 0;
        }
        for (auto& e : edges) {
            capacity[e.first][e.second]++;
        }

        for (int u = 0; u < n1; u++) {
            capacity[n-4][u] = degree[u] - deg;
            capacity[u][n-4] = 0;
        }
        for (int v = n1; v < n1 + n2; v++) {
            capacity[v][n-3] = degree[v] - deg;
            capacity[n-3][v] = 0;
        }
    };
    fill_capacity(1);
    ek.determine_adj();
    
    cout << 0 << '\n';
    for (int degree = 1; degree <= minDegree; degree++) {
        fill_capacity(degree);
        cout << m - ek.maxflow(n-4, n-3);
        for (int i = 0; i < m; i++) {
            auto [u, v] = edges[i];
            if (ek.capacity[v][u] > 0) {
                ek.capacity[v][u]--;
            } else {
                cout << " " << i + 1;
            }
        }
        cout << '\n';
    }
}