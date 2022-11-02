#include <bits/stdc++.h>

std::vector<std::vector<std::vector<int> > > I(
    {{},
     {},
     {{1, 1}, {0, 0}},
     {},
     {{1, 1, 1, 1}, {0, 1, 1, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}},
     {},
     {{1, 1, 1, 1, 1, 1},
      {0, 1, 1, 1, 1, 0},
      {1, 1, 0, 0, 1, 1},
      {0, 1, 1, 1, 1, 0},
      {1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0}},
     {},
     {{1, 1, 1, 1, 1, 1, 1, 1},
      {0, 1, 1, 1, 1, 1, 1, 0},
      {1, 1, 0, 0, 0, 0, 1, 1},
      {0, 1, 1, 0, 0, 1, 1, 0},
      {1, 1, 0, 0, 0, 0, 1, 1},
      {0, 1, 1, 1, 1, 1, 1, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 0, 0, 0}}});

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int> > a(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) std::cin >> a[i][j];
        }
        int Ans = 0;
        using SolveT = std::function<void(int, int)>;
        SolveT Solve = [&](int C, int n) -> void {
            auto Get = [&](int x, int y) -> void { Ans ^= a[C + x][C + y]; };
            if (n <= 8) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (I[n][i][j]) Get(i, j);
                    }
                }
            } else {
                for (int i = 0; i < n; ++i) Get(0, i), Get(n - 2, i);
                for (int i = 1; i + 1 < n; ++i) Get(1, i), Get(n - 3, i);
                for (int i = 2; i + 3 < n; ++i) {
                    Get(i, i & 1), Get(i, (i & 1) + 1);
                    Get(i, n - 2 - (i & 1)), Get(i, n - 1 - (i & 1));
                }
                Solve(C + 4, n - 8);
            }
        };
        Solve(0, n);
        std::cout << Ans << std::endl;
    }
    return 0;
}

/*
#include <bits/stdc++.h>

const int C = 8;
const int D = C * C;

using Bits = std::bitset<D>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::vector<Bits> a(D), b(D);
    auto Get = [&](int x, int y) { return x * C + y; };
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            int u = Get(i, j);
            b[u][u] = 1;
            if (i) a[u][Get(i - 1, j)] = 1;
            if (j) a[u][Get(i, j - 1)] = 1;
            if (i + 1 < C) a[u][Get(i + 1, j)] = 1;
            if (j + 1 < C) a[u][Get(i, j + 1)] = 1;
        }
    }
    // for (int c = 0; c < D; ++c) {
    //     for (int i = 0; i < C; ++i) {
    //         for (int j = 0; j < C; ++j) {
    //             std::cout << (a[c][Get(i, j)] ? '#' : '.');
    //         }
    //         std::cout << std::endl;
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    for (int i = 0; i < D; ++i) {
        if (!a[i][i]) {
            for (int j = i; j < D; ++j) {
                if (a[j][i]) {
                    std::swap(a[i], a[j]);
                    std::swap(b[i], b[j]);
                    break;
                }
            }
        }
        for (int j = 0; j < D; ++j) {
            if (j != i && a[j][i]) a[j] ^= a[i], b[j] ^= b[i];
        }
    }
    // for (int i = 0; i < D; ++i) {
    //     for (int j = 0; j < D; ++j) std::cout << a[i][j];
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    // for (int i = 0; i < D; ++i) {
    //     for (int j = 0; j < D; ++j) std::cout << b[i][j];
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    Bits c;
    for (int i = 0; i < D; ++i) c ^= b[i];
    // for (int i = 0; i < 16; ++i) {
    Bits d = c;
    //     for (int j = 0; j < 4; ++j) {
    //         if (i & (1 << j)) d ^= b[12 + j];
    //     }
    std::cout << "{";
    for (int i = 0; i < C; ++i) {
        std::cout << '{';
        for (int j = 0; j < C; ++j) {
            if (j) std::cout << ", ";
            std::cout << d[Get(i, j)];
        }
        std::cout << "}";
        if (i != C - 1) std::cout << ", ";
        std::cout << std::endl;
    }
    std::cout << "}";
    //     std::cout << std::endl;
    // }
    return 0;
}
*/