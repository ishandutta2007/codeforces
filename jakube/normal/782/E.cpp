#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> euler;
vector<bool> visited;

void dfs(int u, int p) {
    visited[u] = true;
    euler.push_back(u);
    for (auto next : adj[u]) {
        if (next == p || visited[next]) continue;
        dfs(next, u);
        euler.push_back(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, k;
    cin >> n >> m >> k;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited.assign(n, false);
    
    dfs(0, -1);
    int size = (2*n + k - 1) / k;
    for (int i = 0; i < k; i++) {
        vector<int> w;
        for (int idx = i * size; idx < i * size + size && idx < euler.size(); idx++) {
            w.push_back(euler[idx]);
        }
        if (w.size() == 0)
            w.push_back(1);
        cout << w.size();
        for (auto rn : w)
            cout << ' ' << rn + 1;
        cout << '\n';
    }

}