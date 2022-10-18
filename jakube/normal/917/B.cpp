#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, char>>> adj;
vector<int> topo;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u.first])
            dfs(u.first);
    }
    topo.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u].push_back({v, c});
    }
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }

    vector<vector<char>> result(n, vector<char>(n));
    vector<vector<vector<bool>>> winning(n, vector<vector<bool>>(n, vector<bool>(26, false)));

    for (int i = 0; i < n; i++) {
        int x = topo[i];
        for (int j = 0; j <= i; j++) {
            int y = topo[j];
            for (int z = 0; z < 2; z++) {
                int mi = 0;
                for (auto edge : adj[x]) {
                    if (!winning[y][edge.first][edge.second - 'a']) {
                        for (int k = mi; k <= edge.second - 'a'; k++) {
                            winning[x][y][k] = true;
                        }
                        mi = max(mi, edge.second - 'a' + 1);
                    }
                }
                swap(x, y);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (winning[i][j][0] ? 'A' : 'B');
        }
        cout << '\n';
    }
}