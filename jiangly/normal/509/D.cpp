#include <bits/stdc++.h>
using i64 = long long;
constexpr int inf = 1e9 + 1;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector w(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> w[i][j];
        }
    }
    int k = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            k = std::gcd(k, w[i][j] + w[i + 1][j + 1] - w[i][j + 1] - w[i + 1][j]);
        }
    }
    if (k == 0) {
        k = inf;
    }
    std::vector<int> a(n), b(m);
    a[0] = w[0][0];
    for (int i = 1; i < n; i++) {
        a[i] = (a[i - 1] + w[i][0] - w[i - 1][0]) % k;
        if (a[i] < 0) {
            a[i] += k;
        }
    }
    for (int j = 1; j < m; j++) {
        b[j] = (b[j - 1] + w[0][j] - w[0][j - 1]) % k;
        if (b[j] < 0) {
            b[j] += k;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (w[i][j] != (a[i] + b[j]) % k) {
                std::cout << "NO\n";
                return 0;
            }
        }
    }
    std::cout << "YES\n";
    std::cout << k << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < m; i++) {
        std::cout << b[i] << " \n"[i == m - 1];
    }
    return 0;
}