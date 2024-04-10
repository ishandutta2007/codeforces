#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
vector<vector<int>> adj;
vector<bool> visited;

int dfs(int x) {
    visited[x] = true;
    int m = v[x];
    for (int u : adj[x]) {
        if (!visited[u]) {
            m = min(m, dfs(u));
        }
    }
    return m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int q;
    cin >> q;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    adj.resize(n);
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.assign(n, false);
    long long s = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            s += dfs(i);
    }
    cout << s << endl;
}