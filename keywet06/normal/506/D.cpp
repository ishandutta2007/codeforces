#include <bits/stdc++.h>
using pai = std::pair<int, int>;
const int N = 100003;
int n, m, q;
std::unordered_map<int, int> fa[N], ans[N];
inline int getfa(int x, int col) {
    return fa[x][col] == x ? x : (fa[x][col] = getfa(fa[x][col], col));
}
inline void merge(int x, int y, int col) {
    if (!fa[x].count(col)) fa[x][col] = x;
    if (!fa[y].count(col)) fa[y][col] = y;
    x = getfa(x, col);
    y = getfa(y, col);
    if (x != y) fa[x][col] = y;
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        merge(a, b, c);
    }
    std::cin >> q;
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        if (fa[u].size() > fa[v].size()) std::swap(u, v);
        if (ans[u].count(v)) {
            std::cout << ans[u][v] << '\n';
            continue;
        }
        int res = 0;
        for (pai t : fa[u]) {
            res += (fa[v].count(t.first) &&
                    getfa(u, t.first) == getfa(v, t.first));
        }
        std::cout << (ans[u][v] = res) << '\n';
    }
}