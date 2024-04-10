#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e3 + 5;

int n, rt, mid, now, tot, ft[N], a[N], p[N], siz[N];
std::vector<int> e[N];

void dfs0(int u) {
    siz[u] = 1;
    for (auto v : e[u]) {
        dfs0(v); siz[u] += siz[v];
    }
}

void dfs2(int u) {
    p[u] += now;
    if (p[u] >= mid) { p[u]++; }
    for (auto v : e[u]) { dfs2(v); }
}

void dfs1(int u) {
    for (auto v : e[u]) { dfs1(v); }
    tot = 0; p[u] = a[u] + 1; mid = p[u];
    for (auto v : e[u]) {
        now = tot;
        dfs2(v);
        tot += siz[v];
    }
}

int main() {
    n = read();
    for (int u = 1; u <= n; u++) {
        ft[u] = read(); a[u] = read();
        if (ft[u] == 0) {
            rt = u;
        } else {
            e[ft[u]].push_back(u);
        }
    }
    dfs0(rt);
    for (int u = 1; u <= n; u++) {
        if (siz[u] - 1 < a[u]) {
            printf("NO\n");
            return 0;
        }
    }
    dfs1(rt);
    printf("YES\n");
    for (int u = 1; u <= n; u++) {
        printf("%d ", p[u]);
    }
    return 0;
}