#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> lines;
vector<int> V;

vector<int> locks;
vector<bool> visited;

vector<int> cur;

bool dfs(int u, int val) {
    if (visited[u]) {
        return locks[u] == val;
    }

    cur.push_back(u);
    visited[u] = true;
    locks[u] = val;

    for (int next : adj[u]) {
        int v = lines[next] - u;

        int next_val = (V[next] + val + 1) & 1;

        if (!dfs(v, next_val))
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    V.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    adj.resize(m);
    lines.assign(n, 0);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        adj[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> adj[i][j];
            adj[i][j]--;
            lines[adj[i][j]] += i;
        }
    }

    visited.assign(m, false);
    locks.assign(m, -1);
    for (int i = 0; i < m; i++) {
        if (!visited[i]) {
            if (!dfs(i, 0)) {
                for (int t : cur)
                    visited[t] = false;
                cur.clear();

                if (!dfs(i, 1)) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    
    cout << "YES" << endl;
}