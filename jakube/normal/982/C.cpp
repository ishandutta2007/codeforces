#include <bits/stdc++.h>
using namespace std;

int comp = 0;
vector<vector<int>> adj;

int dfs(int v, int p) {
    int s = 1;
    for (int u : adj[v]) {
        if (u == p)
            continue;
        s += dfs(u, v);
    }
    if (s % 2 == 0)
        comp++;
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if (n % 2) {
        cout << -1 << '\n';
        return 0;
    }

    dfs(0, -1);
    cout << comp - 1 << '\n';
}