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

vector<bool> visited, explored;
bool has_cycle(SCC const& scc, int cur, int u, int v) {
    visited[cur] = true;

    for (int next : scc.adj[cur]) {
        if (cur == u && next == v)
            continue;
        if (visited[next]) {
            visited[cur] = false;
            return true;
        } 
    
        if (explored[next])
            continue;

        if (has_cycle(scc, next, u, v)) {
            visited[cur] = false;
            return true;
        } 
    }

    visited[cur] = false;
    explored[cur] = true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    SCC scc(n);
    using Edge = pair<int, int>;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        scc.add_edge(u - 1, v - 1);
        edges[i] = {u-1, v-1};
    }

    scc.solve();
    int cnt = 0;
    int c = 0;
    for (auto& comp : scc.components) {
        if (comp.size() > 1) {
            cnt++;
            c = scc.component[comp[0]];
        }
    }
    if (cnt > 1) {
        cout << "NO" << '\n';
        return 0;
    }
    if (cnt == 0) {
        cout << "YES" << '\n';
        return 0;
    }

    visited.assign(n, false);
    explored.assign(n, false);
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        if (scc.component[u] != c || scc.component[v] != c)
            continue;

        fill(explored.begin(), explored.end(), false);
        if (!has_cycle(scc, v, u, v)) {
            cout << "YES" << '\n';
            return 0;
        }
    }

    cout << "NO" << '\n';
}