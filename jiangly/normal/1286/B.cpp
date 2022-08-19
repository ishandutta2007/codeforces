#include <iostream>
#include <vector>
#include <algorithm>
int n, dfn;
std::vector<std::vector<int>> e;
std::vector<int> c, a, sz, in, out;
void dfs(int u) {
    in[u] = dfn++;
    for (int v : e[u]) {
        dfs(v);
        for (int i = in[v]; i < out[v]; ++i)
            a[i] += sz[u];
        sz[u] += sz[v];
    }
    ++sz[u];
    if (c[u] >= sz[u]) {
        std::cout << "NO\n";
        exit(0);
    }
    out[u] = dfn;
    a[in[u]] = c[u];
    for (int i = in[u] + 1; i < out[u]; ++i)
        if (a[i] >= c[u])
            ++a[i];
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    e.resize(n);
    c.resize(n);
    a.resize(n);
    sz.resize(n);
    in.resize(n);
    out.resize(n);
    int rt;
    for (int i = 0; i < n; ++i) {
        int p;
        std::cin >> p >> c[i];
        if (p == 0) {
            rt = i;
        } else {
            e[p - 1].push_back(i);
        }
    }
    dfs(rt);
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i)
        std::cout << a[in[i]] + 1 << " \n"[i == n - 1];
    return 0;
}