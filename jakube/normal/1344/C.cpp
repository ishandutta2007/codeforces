#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<vector<int>> adj_up;
vector<char> color;
vector<char> res;
vector<int> up, down;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool has_cycle() {
    color.assign(n, 0);
    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v))
            return true;
    }
    return false;
}

int lowest_up(int v) {
    if (up[v] == -1) {
        int lowest = v;
        for (int u : adj_up[v]) {
            lowest = min(lowest, lowest_up(u));
        }
        up[v] = lowest;
    }
    return up[v];
}

int lowest_down(int v) {
    if (down[v] == -1) {
        int lowest = v;
        for (int u : adj[v]) {
            lowest = min(lowest, lowest_down(u));
        }
        down[v] = lowest;
    }
    return down[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    adj.resize(n);
    adj_up.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj_up[v].push_back(u);
    }
    
    if  (has_cycle()) {
        cout << -1 << '\n';
        return 0;
    }

    int count = 0;
    up.assign(n, -1);
    down.assign(n, -1);
    res.assign(n, 'E');
    for (int i = 0; i < n; i++) {
        if (lowest_up(i) == i && lowest_down(i) == i) {
            res[i] = 'A';
            count++;
        }
    }

    cout << count << '\n';
    for (char c : res)
        cout << c;
    cout << '\n';
}