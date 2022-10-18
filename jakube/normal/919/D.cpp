#include <bits/stdc++.h>
using namespace std;

class SCC
{
public:
    SCC(int n) : n(n) {
        adj.resize(n);
        adj_t.resize(n);
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj_t[v].push_back(u);
    }

    int solve()
    {
        visited.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                dfs1(i);
        }
        visited.assign(n, false);
        reverse(order.begin(), order.end());
        components.clear();
        component.resize(n);
        int c = 0;
        for (int i : order) {
            if (!visited[i]) {
                components.push_back({});
                dfs2(i, c);
                c++;
            }
        }

        adj_condensation.resize(c);
        for (int v = 0; v < n; v++) {
            for (int u : adj[v]) {
                if (component[v] != component[u])
                    adj_condensation[component[v]].push_back(component[u]);
            }
        }

        return c;
    }

    void dfs1(int v)
    {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int c)
    {
        visited[v] = true;
        components.back().push_back(v);
        component[v] = c;
        for (int u : adj_t[v]) {
            if (!visited[u])
                dfs2(u, c);
        }
    }

    int n;
    std::vector<std::vector<int>> adj, adj_t, components, adj_condensation;
    std::vector<bool> visited;
    std::vector<int> order, component;
};

string s;
vector<vector<int>> adj;
vector<vector<int>> dp;
vector<bool> visited;

int res = 0;

void dfs(int v, int p) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (!visited[u])
            dfs(u, v);
        
        for (int i = 0; i < 26; i++) {
            dp[v][i] = max(dp[v][i], dp[u][i]);
        }
    }
    dp[v][s[v] - 'a']++;
    res = max(res, dp[v][s[v] - 'a']);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    cin >> s;
    SCC scc(n);
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u == v) {
            cout << -1 << '\n';
            return 0;
        }
        adj[u].push_back(v);
        scc.add_edge(u, v);
    }
    scc.solve();
    for (auto c : scc.components) {
        if (c.size() > 1) {
            cout << -1 << '\n';
            return 0;
        }
    }

    visited.assign(n, false);
    dp.assign(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }
    cout << res << '\n';
}