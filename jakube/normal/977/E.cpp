#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

vector<int> comp;
void dfs(int v) {
    visited[v] = true;
    comp.push_back(v);
    for (int u : adj[v]) {
        if (visited[u])
            continue;
        dfs(u);
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
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            comp.clear();
            dfs(i);
            bool b = true;
            for (int x : comp) {
                if (adj[x].size() != 2)
                    b = false;
            }

            if (b) {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    
}