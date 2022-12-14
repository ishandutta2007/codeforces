#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e2 + 5;

int n, k0, k1, a[N], f[2][N][N][N];

void dp0(int i) {
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            f[0][i][x][y] = std::min(f[0][i][x][y], f[0][i - 1][x + 1][y]);
            f[0][i][x][y] = std::min(f[0][i][x][y], f[1][i - 1][x + 1][y] + 1);
        }
    }
}
void dp1(int i) {
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            f[1][i][x][y] = std::min(f[1][i][x][y], f[1][i - 1][x][y + 1]);
            f[1][i][x][y] = std::min(f[1][i][x][y], f[0][i - 1][x][y + 1] + 1);
        }
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) { k0++; }
        if (i % 2 == 1) { k1++; }
    }
    memset(f, 127, sizeof(f));
    f[0][0][k0][k1] = 0; f[1][0][k0][k1] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            if (a[i] % 2 == 0) { dp0(i); }
            if (a[i] % 2 == 1) { dp1(i); }
        } else {
            dp0(i); dp1(i);
        }
    }
    printf("%d\n", std::min(f[0][n][0][0], f[1][n][0][0]));
    return 0;
}