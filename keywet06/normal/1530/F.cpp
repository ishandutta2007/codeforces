#include <bits/stdc++.h>

const int P = 31607;
const int I = 3973;
const int B = 2;
const int N_ = 21;
const int N = N_ + 5;
const int Np = N_ + 2;
const int M = 1 << Np;

int n, p, c;
int inv[P];
int g[N];
int a[N][N], b[N][N];
int f[B][M];

inline void dfs(int d, int v) {
    if (d == n + 2) {
        f[c][v] = 1;
        for (int i = 0; i < n; ++i) f[c][v] = f[c][v] * (1 - g[i] + P) % P;
        return;
    }
    dfs(d + 1, v);
    if (d < n) {
        for (int i = 0; i < n; ++i) g[i] = g[i] * b[d][i] % P;
    } else if (d == n) {
        for (int i = 0; i < n; ++i) {
            if (!(v >> i & 1)) g[i] = g[i] * b[i][i] % P;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (!(v >> n - 1 - i & 1 || v >> n & 1 && i == n - 1 - i)) {
                g[i] = g[i] * b[n - 1 - i][i] % P;
            }
        }
    }
    dfs(d + 1, v | 1 << d);
    if (d < n) {
        for (int i = 0; i < n; ++i) g[i] = g[i] * a[d][i] % P;
    } else if (d == n) {
        for (int i = 0; i < n; ++i) {
            if (!(v >> i & 1)) g[i] = g[i] * a[i][i] % P;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (!(v >> n - 1 - i & 1 || v >> n & 1 && i == n - 1 - i)) {
                g[i] = g[i] * a[n - 1 - i][i] % P;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    inv[0] = inv[1] = 1;
    for (int i = 2; i < P; ++i) inv[i] = (P - P / i) * inv[P % i] % P;
    std::cin >> n;
    for (int i = 0; i < n; ++i) g[i] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j], a[i][j] = a[i][j] * I % P;
            b[i][j] = inv[a[i][j]], g[j] = g[j] * a[i][j] % P;
        }
    }
    dfs(0, 0);
    c ^= 1;
    for (int i = 0; i < 1 << n + 1; ++i) {
        p = 1;
        for (int x = 0; x < n; ++x) {
            if (!(i >> x & 1 || i >> n & 1 && x == n - 1 - x)) {
                p = p * a[x][n - 1 - x] % P;
            }
        }
        f[c][i] = ((f[!c][i] - f[!c][i | 1 << n + 1] * p) % P + P) % P;
    }
    c ^= 1;
    for (int i = 0; i < 1 << n; ++i) {
        p = 1;
        for (int x = 0; x < n; ++x) {
            if (!(i >> x & 1)) p = p * a[x][x] % P;
        }
        f[c][i] = ((f[!c][i] - f[!c][i | 1 << n] * p) % P + P) % P;
    }
    c ^= 1;
    for (int i = n - 1; ~i; --i) {
        for (int j = 0; j < 1 << i; ++j) {
            p = 1;
            for (int x = 0; x < n; ++x) p = p * a[i][x] % P;
            f[c][j] = ((f[!c][j] - f[!c][j | 1 << i] * p) % P + P) % P;
        }
        c ^= 1;
    }
    std::cout << (P + 1 - f[!c][0]) % P << std::endl;
    return 0;
}