#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> leader;
vector<int> s;

int dfs(int v, int l) {
    if (visited[v]) return 0;
    visited[v] = true;
    leader[v] = l;

    int size = 1;
    for (int u : adj[v]) {
        size += dfs(u, l);
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    visited.assign(n+1, false);
    leader.resize(n+1);
    s.resize(n+1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            s[i] = dfs(i, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() < s[leader[i]] - 1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}