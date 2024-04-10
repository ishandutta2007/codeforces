#include <bits/stdc++.h>

const int N = 100005;

struct edge {
    int v, p, f;
} Test;

int n, m, vis[N];

std::vector<edge> To[N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::cin >> n >> m;
    for (int i = 1, u, v, f; i <= m; ++i) {
        std::cin >> u >> v >> f;
        Test.v = v, Test.p = i, Test.f = f;
        To[u].push_back(Test);
    }
    std::queue<int> Q;
    Q.push(1), vis[1] = -1;
    while (!Q.empty()) {
        int p = Q.front();
        Q.pop();
        for (int i = 0; i < To[p].size(); ++i) {
            int v = To[p][i].v, f = To[p][i].f, id = To[p][i].p;
            if (!vis[v] || (vis[v] > 0 && !f)) vis[v] = f ? id : -1, Q.push(v);
        }
    }
    std::vector<int> v;
    int flag = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) flag = 1;
        if (vis[i] != -1) v.push_back(vis[i]);
    }
    if (flag) {
        std::cout << -1 << '\n';
    } else {
        std::cout << v.size() << '\n';
        for (int i = 0; i < v.size(); ++i) std::cout << v[i] << '\n';
    }
    return 0;
}