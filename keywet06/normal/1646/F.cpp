#include <bits/stdc++.h>

const int N = 105;

int n;
int Now[N][N];
int k, Ans[N * N][N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1, x; j <= n; ++j) std::cin >> x, ++Now[i][x];
    }
    while (true) {
        int p = -1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (Now[i][j] > 1 && (p = i)) break;
            }
            if (p == i) break;
        }
        if (p == -1) break;
        ++k;
        for (int i = p, c, q = -1; c = i == n ? 1 : i + 1, i != p || q == -1; i = c) {
            for (int j = 1; j <= n; ++j) {
                if (Now[i][j] > 1 && (q = j)) break;
            }
            --Now[i][q], ++Now[c][q], Ans[k][i] = q;
        }
    }
    std::cout << k + n * (n - 1) / 2 << '\n';
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) std::cout << Ans[i][j] << " \n"[j == n];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i; j; --j) {
            for (int k = 1; k <= n; ++k) std::cout << (k + j > n ? k + j - n : k + j) << " \n"[k == n];
        }
    }
    return 0;
}