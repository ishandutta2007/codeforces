#include <iostream>
#include <vector>
#include <algorithm>
int n, clc;
std::vector<std::vector<int>> e;
std::vector<int> parent, in, height, f, k;
void dfs1(int u) {
    if (parent[u] != -1)
        e[u].erase(std::find(e[u].begin(), e[u].end(), parent[u]));
    height[u] = 1;
    for (int &v : e[u]) {
        parent[v] = u;
        dfs1(v);
        if (height[v] >= height[e[u][0]]) {
            height[u] = height[v] + 1;
            std::swap(v, e[u][0]);
        }
    }
}
void dfs2(int u) {
    in[u] = clc++;
    f[in[u]] = 1;
    for (int &v : e[u]) {
        dfs2(v);
        if (v == e[u][0]) {
            if (f[in[v] + k[v]] > 1)
                k[u] = k[v] + 1;
        } else {
            for (int i = 0; i < height[v]; ++i) {
                f[in[u] + i + 1] += f[in[v] + i];
                if (f[in[u] + i + 1] > f[in[u] + k[u]] || f[in[u] + i + 1] == f[in[u] + k[u]] && i + 1 < k[u])
                    k[u] = i + 1;
            }
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    e.resize(n);
    parent.resize(n);
    in.resize(n);
    height.resize(n);
    f.resize(n);
    k.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    parent[0] = -1;
    dfs1(0);
    dfs2(0);
    for (int i = 0; i < n; ++i)
        std::cout << k[i] << "\n";
    return 0;
}