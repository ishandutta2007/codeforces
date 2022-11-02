#include <bits/stdc++.h>

const int N = 100005;
const int P = 18;

int H[N], nn, fir[N], las[N];
int table[P][N * 2];

std::vector<int> E[N];

void go(int x, int p = -1) {
    fir[x] = nn;
    table[0][nn++] = x;
    for (auto y : E[x]) {
        if (y == p) continue;
        H[y] = H[x] + 1;
        go(y, x);
        table[0][nn++] = x;
    }
    las[x] = nn - 1;
}

int getLCA(int a, int b) {
    a = fir[a], b = fir[b];
    if (a > b) std::swap(a, b);
    int d = b - a + 1, p = 31 - __builtin_clz(d);
    int x = table[p][a], y = table[p][b - (1 << p) + 1];
    return H[x] < H[y] ? x : y;
}

int up[N][2];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int par, typ;
        scanf("%d%d", &par, &typ);
        if (par == -1) par = 0;
        E[par].push_back(i);
        up[i][0] = up[i][1] = i;
        if (typ == -1) continue;
        up[i][typ] = up[par][typ];
    }
    go(0);
    for (int p = 1; p < P; ++p) {
        for (int i = 0; i < nn; ++i) {
            if (i + (1 << p) - 1 < nn) {
                int x = table[p - 1][i], y = table[p - 1][i + (1 << (p - 1))];
                table[p][i] = H[x] < H[y] ? x : y;
            }
        }
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int typ, u, v;
        scanf("%d%d%d", &typ, &u, &v);
        auto ok = [&]() {
            if (u == v) return false;
            int lca = getLCA(u, v);
            if (typ == 1) return u == lca && H[up[v][0]] <= H[lca];
            if (v == lca) return false;
            return H[up[v][1]] <= H[lca] && H[up[u][0]] <= H[lca];
        };
        printf(ok() ? "YES\n" : "NO\n");
    }
    return 0;
}