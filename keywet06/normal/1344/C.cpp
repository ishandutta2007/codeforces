#include <bits/stdc++.h>

const int N = 200005;

int n, m, x, y;
int in[N], tp[N], pre[N], don[N];

std::queue<int> q;

std::vector<int> to[N], dto[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        std::cin >> x >> y;
        to[x].push_back(y), dto[y].push_back(x), ++in[y];
    }
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) q.push(i);
    }
    y = 0;
    while (!q.empty()) {
        x = tp[++y] = q.front(), q.pop();
        for (int u : to[x]) {
            if (!--in[u]) q.push(u);
        }
    }
    if (y < n) return std::cout << -1 << std::endl, 0;
    for (int i = 1; i <= n; ++i) pre[i] = don[i] = i;
    for (int i = 1; i <= n; ++i) {
        for (int u : dto[tp[i]]) pre[tp[i]] = std::min(pre[tp[i]], pre[u]);
        for (int u : to[x = tp[n - i + 1]]) don[x] = std::min(don[x], don[u]);
    }
    x = 0;
    for (int i = 1; i <= n; ++i) x += pre[i] == i && don[i] == i;
    std::cout << x << std::endl;
    for (int i = 1; i <= n; ++i) {
        std::cout << (pre[i] == i && don[i] == i ? 'A' : 'E');
    }
    std::cout << std::endl;
    return 0;
}