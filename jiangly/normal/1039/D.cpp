#include <iostream>
#include <algorithm>
#include <vector>
constexpr int N = 100'000, T = 1'000;
int n, clc;
int ans[N], f[N], g[N], in[N], parent[N];
std::vector<int> e[N];
void dfs(int u, int p) {
    in[u] = clc++;
    for (int v : e[u]) {
        if (v != p) {
            dfs(v, u);
            parent[in[v]] = in[u];
        }
    }
}
int solve(int k) {
    if (ans[k - 1] != -1)
        return ans[k - 1];
    ans[k - 1] = 0;
    std::fill(f, f + n, 0);
    std::fill(g, g + n, 0);
    for (int i = n - 1; i > 0; --i) {
        if (f[i] + g[i] + 1 >= k) {
            ++ans[k - 1];
        } else {
            int x = f[i] + 1;
            if (x > f[parent[i]])
                std::swap(x, f[parent[i]]);
            g[parent[i]] = std::max(x, g[parent[i]]);
        }
    }
    if (f[0] + g[0] + 1 >= k)
        ++ans[k - 1];
    return ans[k - 1];
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    std::fill(ans, ans + n, -1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    parent[0] = -1;
    dfs(0, -1);
    for (int i = 1; i <= n && i <= T; ++i)
        solve(i);
    for (int i = T, v = ans[T - 1]; v > 0; --v) {
        int l = i, r = n;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (solve(m) == v) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        while (i < l) {
            ++i;
            ans[i - 1] = v;
        }
    }
    for (int i = 0; i < n; ++i)
        std::cout << std::max(0, ans[i]) << "\n";
    return 0;
}