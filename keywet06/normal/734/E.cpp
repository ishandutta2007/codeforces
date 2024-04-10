#include <bits/stdc++.h>
const int N = 200005;
const int M = 400005;
int n, cnt, ans, pu, pv;
int c[N], head[N], deep[N], dep2[N];
int next[M], to[M], val[M];
inline void insert(int u, int v, int value) {
    next[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    val[cnt] = value;
}
inline void addedge(int u, int v, int value) {
    insert(u, v, value);
    insert(v, u, value);
}
inline void dfs(int u, int f) {
    int max = 0, max2 = 0;
    for (int e = head[u]; e; e = next[e]) {
        if (to[e] == f) continue;
        dep2[to[e]] = deep[to[e]] = deep[u] + val[e];
        dfs(to[e], u);
        dep2[u] = std::max(dep2[u], dep2[to[e]]);
        max2 = std::max(max2, dep2[to[e]] - deep[u]);
        if (max2 > max) std::swap(max, max2);
    }
    ans = std::max(ans, max + max2);
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> c[i];
    for (int i = 1; i < n; ++i) {
        std::cin >> pu >> pv;
        addedge(pu, pv, c[pu] != c[pv]);
    }
    dfs(1, 1);
    std::cout << (ans + 1) / 2 << std::endl;
    return 0;
}