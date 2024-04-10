#include <bits/stdc++.h>

const int P = 998244353;

int n;

std::vector<int> f, g, h, pre, suf;
std::vector<std::vector<int>> e;

void dfs(int u, int p) {
    for (int v : e[u]) {
        if (v != p) dfs(v, u);
    }
    int d = std::find(e[u].begin(), e[u].end(), p) - e[u].begin();
    if (d != int(e[u].size())) e[u].erase(e[u].begin() + d);
    pre = {1};
    for (int v : e[u]) pre.push_back(1LL * pre.back() * (g[v] + h[v]) % P);
    suf.resize(e[u].size() + 1);
    suf.back() = 1;
    for (int i = int(e[u].size()) - 1; i >= 0; --i) {
        int v = e[u][i];
        suf[i] = 1LL * suf[i + 1] * (f[v] + h[v]) % P;
    }
    g[u] = 1LL * pre[d] * suf[d] % P;
    f[u] = pre.back();
    for (int i = 0; i < int(e[u].size()); ++i) {
        int v = e[u][i];
        if (i < d) {
            h[u] = (h[u] + 1LL * pre[i] * f[v] % P * suf[i + 1]) % P;
        } else {
            f[u] = (f[u] + 1LL * pre[i] * f[v] % P * suf[i + 1]) % P;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    e.resize(n);
    f.resize(n);
    g.resize(n);
    h.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v, --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(0, -1);
    std::cout << (g[0] + h[0]) % P << "\n";
    return 0;
}