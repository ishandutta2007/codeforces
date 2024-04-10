#include <bits/stdc++.h>

const int N = 1000005;

int n, m, x, y, ans, cnt;
int c[N], v[N], head[N], next[N], to[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        std::cin >> x >> y;
        next[++cnt] = head[x];
        head[x] = cnt;
        to[cnt] = y;
    }
    for (int i = 1; i <= n; ++i) {
        if (v[i]) continue;
        v[i] = c[i] = 1;
        for (int e = head[i]; e; e = next[e]) v[to[e]] = 1;
    }
    for (int i = n; i; --i) {
        if (!c[i]) continue;
        for (int e = head[i]; e; e = next[e]) c[to[e]] = 0;
    }
    for (int i = 1; i <= n; ++i) ans += c[i];
    std::cout << ans << std::endl;
    for (int i = 1; i <= n; ++i) {
        if (c[i]) std::cout << i << ' ';
    }
    std::cout << std::endl;
    return 0;
}