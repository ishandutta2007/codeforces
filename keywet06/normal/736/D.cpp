#include <bits/stdc++.h>

const int N = 2010, M = 500010;

int n, m, u[M], v[M];

std::bitset<N> b[N], c[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) scanf("%d %d", &u[i], &v[i]), b[u[i]].set(v[i]);
    for (int i = 1; i <= n; ++i) c[i].set(i);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) if (b[j][i]) { std::swap(b[i], b[j]); std::swap(c[i], c[j]); break; }
        for (int j = 1; j <= n; ++j) if (i ^ j && b[j][i]) b[j] ^= b[i], c[j] ^= c[i];
    }
    for (int i = 1; i <= m; ++i) puts(c[v[i]][u[i]] ? "NO" : "YES");
    return 0;
}