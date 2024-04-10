#include <bits/stdc++.h>
const int N = 200005;
int n;
int r[N], x[N], y[N];
std::vector<int> to[N];
inline void addedge(int x, int y) {
    to[x].push_back(y);
    to[y].push_back(x);
}
inline void dfs(int u, int c) {
    r[u] = c;
    for (int v : to[u]) {
        if (r[v]) continue;
        dfs(v, 3 - c);
    }
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> x[i] >> y[i], addedge(x[i], y[i]);
    n <<= 1;
    for (int i = 2; i <= n; i += 2) addedge(i - 1, i);
    for (int i = 1; i <= n; ++i) if (!r[i]) dfs(i, 1);
    n >>= 1;
    for (int i = 1; i <= n; ++i) std::cout << r[x[i]] << ' ' << r[y[i]] << '\n';
    return 0;
}