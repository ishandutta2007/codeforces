#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, siz[N], f[N];
long long ans0, ans1;
std::vector<std::pair<int, int>> e[N];

void dfs(int u, int fa) {
    siz[u] = 1; f[u] = 1;
    for (auto i : e[u]) {
        int v = i.first, w = i.second;
        if (v != fa) {
            dfs(v, u);
            siz[u] += siz[v];
            if (f[v]) {
                ans0 += w; f[u] ^= 1;
            }
            ans1 += 1ll * std::min(siz[v], n - siz[v]) * w;
        }
    }
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); n *= 2;
        for (int u = 1; u <= n; u++) { e[u].clear(); }
        for (int i = 1; i < n; i++) {
            int u = read(), v = read(), w = read();
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        ans0 = ans1 = 0; dfs(1, 0);
        printf("%I64d %I64d\n", ans0, ans1);
    }
    return 0;
}