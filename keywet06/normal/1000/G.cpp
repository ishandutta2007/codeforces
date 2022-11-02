#include <bits/stdc++.h>

const long long N = 300005;

int n, tim;
int dip[N], tin[N], tout[N];
int up[N][20];

long long s[N], A[N], B[N], a[N], e[N], d[N], u[N], f[N], er[N];

std::vector<int> v[N];

void dfs(int x, int p) {
    tin[x] = ++tim;
    up[x][0] = p;
    for (int i = 1; i < 20; ++i) up[x][i] = up[up[x][i - 1]][i - 1];
    d[x] = a[x];
    for (int h : v[x]) {
        int y = A[h] ^ B[h] ^ x;
        if (y == p) continue;
        dip[y] = dip[x] + 1;
        s[y] = s[x] - e[h];
        dfs(y, x);
        d[x] += std::max(0ll, d[y] - e[h] - e[h]);
    }
    for (int h : v[x]) {
        int y = A[h] ^ B[h] ^ x;
        if (y == p) continue;
        f[y] = d[x] - std::max(0ll, d[y] - e[h] - e[h]);
        er[y] = std::max(0ll, d[y] - e[h] - e[h]);
    }
    tout[x] = ++tim;
}

void go(int x, int p) {
    for (int h : v[x]) {
        int y = A[h] ^ B[h] ^ x;
        if (y == p) continue;
        u[y] = std::max(0ll, u[x] + f[y] - e[h] - e[h]);
        f[y] += f[x];
        go(y, x);
    }
}

bool is(int x, int y) { return tin[x] <= tin[y] && tout[x] >= tout[y]; }

int lca(int x, int y) {
    if (is(x, y)) return x;
    if (is(y, x)) return y;
    for (int i = 19; i >= 0; --i) {
        if (!is(up[x][i], y)) x = up[x][i];
    }
    return up[x][0];
}

int go_up(int x, int g) {
    for (int i = 19; i >= 0; --i) {
        if (g >= (1 << i)) {
            g -= (1 << i);
            x = up[x][i];
        }
    }
    return x;
}

long long get(int x, int y) {
    long long profit = 0;
    int p = lca(x, y);
    profit += d[p];
    if (x != p) {
        int g = go_up(x, dip[x] - dip[p] - 1);
        profit += f[x] - f[g];
        profit += d[x] - er[g];
    }
    if (y != p) {
        int g = go_up(y, dip[y] - dip[p] - 1);
        profit += f[y] - f[g];
        profit += d[y] - er[g];
    }
    profit += s[x] + s[y] - s[p] - s[p];
    profit += u[p];
    return profit;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int q;
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i < n; ++i) {
        std::cin >> A[i] >> B[i] >> e[i];
        v[A[i]].push_back(i);
        v[B[i]].push_back(i);
    }
    dfs(1, 1);
    go(1, 1);
    for (int i = 1; i <= q; ++i) {
        int x, y;
        std::cin >> x >> y;
        std::cout << get(x, y) << "\n";
    }
    return 0;
}