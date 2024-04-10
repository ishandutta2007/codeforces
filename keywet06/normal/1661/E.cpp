#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(3);
    for (int i = 0; i < 3; ++i) {
        std::string s;
        std::cin >> s;
        for (auto c : s) a[i].push_back(c - '0');
    }
    std::vector<int> f(n + 1), g(n);
    for (int i = 0; i < n; ++i) {
        f[i + 1] = f[i] + a[0][i] + a[1][i] + a[2][i] - (a[0][i] & a[1][i]) - (a[1][i] & a[2][i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        g[i + 1] = g[i] - (a[0][i] & a[0][i + 1]) - (a[1][i] & a[1][i + 1]) - (a[2][i] & a[2][i + 1]) +
                   (a[0][i] & a[1][i] & a[0][i + 1] & a[1][i + 1]) + (a[1][i] & a[2][i] & a[1][i + 1] & a[2][i + 1]);
    }
    std::vector<int> R(n), L(n);
    for (int i = 0; i < n - 1; ++i) {
        if (a[0][i] & a[1][i] & a[2][i]) {
            int j = i + 1;
            while (j < n && (a[0][j] & !a[1][j] & a[2][j])) ++j;
            if (j < n && j > i + 1 && a[0][j] && a[1][j] && a[2][j]) {
                ++R[j];
                if (i + 1 < n) ++L[i + 1];
            }
            i = j - 1;
        }
    }
    for (int i = 1; i < n; ++i) L[i] += L[i - 1], R[i] += R[i - 1];
    int q;
    std::cin >> q;
    while (q--) {
        int l, r;
        std::cin >> l >> r, --l;
        std::cout << f[r] - f[l] + g[r - 1] - g[l] + std::max(0, R[r - 1] - L[l]) << "\n";
    }
    return 0;
}