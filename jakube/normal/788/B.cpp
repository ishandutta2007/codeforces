#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

vector<bool> visited;
void dfs(int v) {
    if (visited[v])
        return;
    visited[v] = true;

    for (int next : adj[v]) {
        dfs(next);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    int self_nodes = 0;
    int other_nodes = 0;
    adj.resize(n);
    vector<pair<int, int>> edges;
    edges.reserve(m);
    int start = 0;
    vector<bool> used(n, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        start = u;
        used[u] = true;
        used[v] = true;
        if (u == v)
            self_nodes++;
        else {
            other_nodes++;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges.push_back({u, v});
        }
    }

    long long result = 0;
    result = (long long)(other_nodes) * (long long)self_nodes; 
    result += (long long)self_nodes * (long long)(self_nodes - 1) / 2;
    
    // count odd cities
    // vector<int> size(n);
    // for (int i = 0; i < n; i++) {
    //     size[i] = adj[i].size() * 2;
    // }
    
    long long result2 = 0;
    for (auto e : edges) {
        result2 += adj[e.first].size() + adj[e.second].size() - 2;
    }

    // check
    visited.assign(n, false);
    dfs(start);

    if (visited == used)
        cout << result + result2 / 2 << endl;
    else
        cout << 0 << endl;
    return 0;
}