#include <bits/stdc++.h>

const int N = 1e5;

int n, cnt;
int Fa[N], a[N], p[N], Dep[N], h[N];

std::vector<int> ans;
std::vector<int> e[N];

void Dfs1(int u) {
    h[u] = Dep[u];
    for (int v : e[u]) {
        Dep[v] = Dep[u] + 1;
        Dfs1(v);
        h[u] = std::max(h[u], h[v]);
    }
}

void Dfs2(int u) {
    a[cnt++] = u;
    std::sort(e[u].begin(), e[u].end(),
              [&](int i, int j) { return h[i] < h[j]; });
    for (int v : e[u]) Dfs2(v);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    Fa[0] = -1;
    for (int i = 1; i < n; ++i) std::cin >> Fa[i], e[Fa[i]].push_back(i);
    Dfs1(0), Dfs2(0);
    for (int i = 0; i < n; ++i) std::cout << a[i] << " \n"[i == n - 1];
    p[0] = -1;
    for (int i = 1; i < n; ++i) p[a[i]] = a[i - 1];
    for (int i = 1; i < n; ++i) {
        int u = a[i];
        while (p[u] != Fa[u]) ans.push_back(u), p[u] = p[p[u]];
    }
    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}