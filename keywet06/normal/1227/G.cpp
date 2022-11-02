#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::iota(b.begin(), b.end(), 0);
    std::sort(b.begin(), b.end(), [&](int i, int j) { return a[i] < a[j]; });
    std::vector<std::vector<int>> c(n + 1);
    for (int i = 0; i <= n; ++i) c[i].resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[b[i]]; ++j) {
            c[(n + 1 + i - j) % (n + 1)][b[i]] = 1;
        }
    }
    std::cout << n + 1 << "\n";
    for (int i = 0; i < n + 1; ++i, std::cout << "\n") {
        for (int j = 0; j < n; ++j) std::cout << c[i][j];
    }
    return 0;
}