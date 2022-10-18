#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to;
    long long w;
};

vector<vector<Edge>> adj;
vector<int> comp;
vector<bool> visited;
vector<long long> a;
vector<long long> res;

void dfs(int v) {
    comp.push_back(v);
    visited[v] = true;
    for (auto& e : adj[v]) {
        if (!visited[e.to])
            dfs(e.to);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        long long w;
        cin >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    res.assign(n, -1);

    visited.assign(n, false);
    for (int v = 0; v < n; v++) {
        if (visited[v]) continue;
        comp.clear();
        dfs(v);

        priority_queue<pair<long long, int>> pq;
        for (int u : comp)
            pq.push({-a[u], u});

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if (res[p.second] == -1) {
                res[p.second] = -p.first;
                for (auto& e : adj[p.second]) {
                    pq.push({p.first - 2*e.w, e.to});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
}