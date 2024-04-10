#include <bits/stdc++.h>

const int N = 40 + 2, C = 20, Z = (1 << C);

int n, k, Max;
int mx1[Z], mx2[Z];

bool mat[N][N];

inline void calc(int s, int e, int Max[Z]) {
    int n = e - s;
    for (int Mk = 1; Mk < (1 << n); ++Mk) {
        if (__builtin_popcount(Mk) == 1) {
            Max[Mk] = 1;
            continue;
        }
        int p;
        for (int i = 0; i < n; ++i) {
            if (Mk & (1 << i)) p = i;
        }
        bool fl = 1;
        for (int i = 0; i < n; ++i) {
            if (Mk & (1 << i)) {
                Max[Mk] = std::max(Max[Mk], Max[Mk ^ (1 << i)]);
                fl &= (i == p || !mat[s + i][s + p]);
            }
        }
        if (fl) Max[Mk] = std::max(Max[Mk], Max[Mk ^ (1 << p)] + 1);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> mat[i][j];
            mat[i][j] ^= (i != j);
        }
    }
    if (n <= C) {
        calc(0, n, mx1);
        Max = mx1[(1 << n) - 1];
    } else {
        calc(0, C, mx1), calc(C, n, mx2);
        for (int Mk = 0; Mk < (1 << C); ++Mk) {
            int sz = __builtin_popcount(Mk);
            if (mx1[Mk] != sz) continue;
            int r = (1 << (n - C)) - 1;
            for (int i = 0; i < C; ++i) {
                for (int j = C; j < n; ++j) {
                    if ((Mk & (1 << i)) && mat[i][j]) r = (r | (1 << (j - C))) ^ (1 << (j - C));
                }
            }
            Max = std::max(Max, sz + mx2[r]);
        }
    }
    double b = k * 1. / Max;
    std::cout << std::fixed << std::setprecision(10) << b * b * (Max * (Max - 1) / 2) << '\n';
    return 0;
}