#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edge(m);
    vector<vector<int>> e(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        e[--u].push_back(--v);
        e[v].push_back(u);
    }
    vector<int> dfn(n, -1), parent(n, -1);
    vector<vector<pair<int, int>>> c(n);
    int s = -1;
    auto checkCactus = [&]() {
        int dfs_now = 0;
        bool ok = false;
        function<void(int)> dfs = [&](int u) {
            dfn[u] = dfs_now++;
            for (int v : e[u]) {
                if (v == parent[u])
                    continue;
                if (dfn[v] == -1) {
                    parent[v] = u;
                    dfs(v);
                } else if (dfn[v] < dfn[u]) {
                    int x = u, tmp = s;
                    while (x != v) {
                        if (!c[x].empty()) {
                            if (s == -1) {
                                if (tmp == -1)
                                    tmp = x;
                            } else
                                break;
                        }
                        c[x].emplace_back(u, v);
                        x = parent[x];
                    }
                    s = tmp;
                }
            }
        };
        for (int i = 0; i < n; ++i)
            if (dfn[i] == -1)
                dfs(i);
        if (s != -1)
            return;
        cout << "NO" << endl;
        exit(0);
    };
    checkCactus();
    cout << "YES" << "\n";
    int t = s;
    while (t != c[s][0].second && t != c[s][1].second)
        t = parent[t];
    int u = s, v;
    vector<int> path[3];
    while (u != t) {
        path[0].push_back(u);
        u = parent[u];
    }
    path[0].push_back(t);
    path[1].push_back(t);
    path[2].push_back(t);
    tie(u, v) = c[s][0];
    int x = t;
    while (x != v) {
        x = parent[x];
        path[1].push_back(x);
    }
    while (u != s) {
        path[1].push_back(u);
        u = parent[u];
    }
    path[1].push_back(s);
    tie(u, v) = c[s][1];
    x = t;
    while (x != v) {
        x = parent[x];
        path[2].push_back(x);
    }
    while (u != s) {
        path[2].push_back(u);
        u = parent[u];
    }
    path[2].push_back(s);
    reverse(path[1].begin(), path[1].end());
    reverse(path[2].begin(), path[2].end());
    for (int i = 0; i < 3; ++i) {
        cout << path[i].size();
        for (int j : path[i])
            cout << " " << j + 1;
        cout << "\n";
    }
    return 0;
}