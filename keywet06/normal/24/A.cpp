#include <bits/stdc++.h>
const int N = 1005;
int n, ans, cnt, x, y, z;
int head[N], next[N], to[N], val[N];
void insert(int, int, int);
void dfs(int, int, int);
inline void insert(int x, int y, int z) {
    ++cnt;
    next[cnt] = head[x];
    head[x] = cnt;
    to[cnt] = y;
    val[cnt] = z;
}
inline void dfs(int v, int fa, int cost) {
    for (int u = head[v]; u; u = next[u]) {
        if (to[u] == fa) {
            continue;
        }
        if (to[u] == 1) {
            ans = std::min(ans, cost + val[u]);
            continue;
        }
        dfs(to[u], v, cost + val[u]);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &x, &y, &z);
        insert(x, y, 0);
        insert(y, x, z);
    }
    ans = 1e9;
    dfs(1, 1, 0);
    printf("%d\n", ans);
    return 0;
}