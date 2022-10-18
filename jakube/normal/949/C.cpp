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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, h;
    cin >> n >> m >> h;
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    SCC scc(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if ((f[a] + 1) % h == f[b]) {
            scc.add_edge(a, b);
        }
        if ((f[b] + 1) % h == f[a]) {
            scc.add_edge(b, a);
        }
    }
    scc.solve();
    int idx = -1;
    auto& adj = scc.adj_condensation;
    auto& comp = scc.components;
    for (int i = 0; i < (int)adj.size(); i++) {
        if ((int)adj[i].size() == 0 && (idx == -1 || comp[idx].size() > comp[i].size()))
            idx = i;
    }
    cout << comp[idx].size() << '\n';
    for (auto x : comp[idx]) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}