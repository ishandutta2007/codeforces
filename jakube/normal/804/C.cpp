#include <bits/stdc++.h>
using namespace std;


vector<int> result;
vector<vector<int>> adj;
vector<vector<int>> colors;
vector<bool> used;
vector<bool> visited;

void dfs(int v, int p) {
    visited[v] = true;

    for (int c : colors[v]) {
        if (result[c] != -1) {
            if (used[result[c]])
                cout << "Error in node " << v << endl;
            used[result[c]] = true;
        }
    }

    int last_used = 0;
    for (int c : colors[v]) {
        if (result[c] == -1) {
            last_used++;
            while (used[last_used])
                last_used++;
            result[c] = last_used;
        }
    }

    for (int c : colors[v]) {
        used[result[c]] = false;
    }

    for (int u : adj[v])
        if (u != p)
            dfs(u, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    colors.resize(n+1);
    result.assign(m+1, -1);
    used.assign(m+2, false);
    visited.assign(n+1, false);

    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        colors[i].resize(c);
        for (int j = 0; j < c; j++) {
            cin >> colors[i][j];
        }
        sort(colors[i].begin(), colors[i].end());
    }

    adj.resize(n + 1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int most_idx = 0;
    int most = 0;
    for (int i = 1; i <= n; i++) {
        if (colors[i].size() >= most) {
            most = colors[i].size();
            most_idx = i;
        }
    }

    dfs(most_idx, 0);

    for (int i = 1; i <= m; i++) {
        if (result[i] == -1)
            result[i] = 1;
    }

    cout << *max_element(result.begin(), result.end()) << endl;
    for (int i = 1; i <= m; i++) {
        cout << result[i] << ' ';
    }
    cout << endl;
}