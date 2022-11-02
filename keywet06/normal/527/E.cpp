#include <bits/stdc++.h>

using int64 = long long;

int n, E;

std::map<int64, int> f;

std::vector<int> C, q[100200];

void add(int a, int b) {
    ++f[(int64)a * (n + 1) + b];
    q[a].push_back(b);
}

bool usd(int u, int v) {
    if (f[(int64)u * (n + 1) + v] == 0) return 1;
    --f[(int64)u * (n + 1) + v];
    --f[(int64)v * (n + 1) + u];
    return 0;
}

void go(int u) {
    while (q[u].size() > 0) {
        int v = q[u].back();
        q[u].pop_back();
        if (usd(u, v)) continue;
        go(v);
    }
    C.push_back(u);
}

int m, a, b, i, lst;

int main() {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; ++i) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
        ++E;
    }
    for (i = 1; i <= n; ++i) {
        if (q[i].size() % 2) {
            if (lst) {
                add(lst, i);
                add(i, lst);
                lst = 0;
                ++E;
            } else {
                lst = i;
            }
        }
    }
    if (E % 2) add(1, 1), add(1, 1), ++E;
    go(1);
    printf("%d\n", E);
    for (i = 0; i < E; ++i) {
        if (i % 2) {
            printf("%d %d\n", C[i], C[(i + 1) % E]);
        } else {
            printf("%d %d\n", C[(i + 1) % E], C[i]);
        }
    }
    return 0;
}