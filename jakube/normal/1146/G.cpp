#include <bits/stdc++.h>
using namespace std;

class EdmondKarp
{
public:
    EdmondKarp(int n, std::vector<std::vector<int>> capacity)
        : n(n), capacity(capacity) {}
 
    int maxflow(int s, int t) {
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (capacity[i][j] || capacity[j][i])
                    adj[i].push_back(j);
            }
        }

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
    cin.tie(nullptr);

    int n, h, m;
    cin >> n >> h >> m;

    int nodes = n*h + 2 + m;
    int source = 0;
    int sink = 1;
    auto get_norm = [&](int i, int j) {
        if (j == 0)
            return source;
        if (j == h + 1)
            return sink;
        return 2 + i * h + (j - 1);
    };
    auto get_pena = [&](int i) {
        return nodes - 1 - i;
    };

    int INF = std::numeric_limits<int>::max() / 2;
    vector<vector<int>> capacity(nodes, vector<int>(nodes, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= h; j++) {
            capacity[get_norm(i, j)][get_norm(i, j+1)] = h*h - j*j;
        }
    }

    for (int i = 0; i < m; i++) {
        int l, r, x, c;
        cin >> l >> r >> x >> c;
        l--;
        for (int j = l; j < r; j++) {
            capacity[get_norm(j, x+1)][get_pena(i)] = INF;
        }
        capacity[get_pena(i)][sink] = c;
    }

    auto ek = EdmondKarp(nodes, capacity);
    cout << h*h*n - ek.maxflow(source, sink) << endl;
}