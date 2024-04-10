#include <bits/stdc++.h>

using int64 = long long;

const int N = 105;

char p[N][N];

int T, n, m, k, x, y;
int a[N], r[N];

inline char selcol(char a, char b, char c) {
    r[0] = r[1] = r[2] = r[3] = 0;
    r[a - 'a'] = r[b - 'a'] = r[c - 'a'] = 1;
    if (!r[0]) return 'a';
    if (!r[1]) return 'b';
    if (!r[2]) return 'c';
    return 'd';
}

inline void plh(int x, int y) {
    int t = selcol(p[x - 1][y], p[x - 1][y + 1], p[x][y - 1]);
    p[x][y] = p[x][y + 1] = t;
}

inline void pls(int x, int y) {
    int t = selcol(p[x - 1][y], p[x][y - 1], p[x + 1][y - 1]);
    p[x][y] = p[x + 1][y] = t;
}

inline void out(int n, int m) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) std::cout << p[i][j];
        std::cout << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m >> k;
        memset(p, 'a', sizeof(p));
        if (n & 1) {
            if (k < m / 2) {
                std::cout << "NO\n";
                continue;
            }
            k -= m / 2, --n;
            if (k & 1) {
                std::cout << "NO\n";
                continue;
            }
            std::cout << "YES\n";
            x = 1, y = 1;
            while (k) {
                plh(x, y), --k;
                if (++x > n) ++++y, x = 1;
            }
            while (y <= m) {
                pls(x, y), pls(x, y + 1);
                if (++++x > n) ++++y, x = 1;
            }
            for (int i = 1; i <= m; ++++i) plh(n + 1, i);
            out(n + 1, m);
            continue;
        }
        if (m & 1) {
            if (k & 1 || k > m / 2 * n) {
                std::cout << "NO\n";
                continue;
            }
            std::cout << "YES\n";
            x = 1, y = 1;
            while (k) {
                plh(x, y), --k;
                if (++x > n) ++++y, x = 1;
            }
            while (y <= m) {
                pls(x, y), pls(x, y + 1);
                if (++++x > n) ++++y, x = 1;
            }
            out(n, m);
            continue;
        }
        if (k & 1) {
            std::cout << "NO\n";
            continue;
        }
        std::cout << "YES\n";
        x = 1, y = 1;
        while (k) {
            plh(x, y), --k;
            if (++x > n) ++++y, x = 1;
        }
        while (y <= m) {
            pls(x, y), pls(x, y + 1);
            if (++++x > n) ++++y, x = 1;
        }
        out(n, m);
    }
    return 0;
}