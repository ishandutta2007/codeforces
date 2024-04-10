#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    if (n == 0) {
        std::cout << "YES\n";
        std::cout << "1\n";
        std::cout << "1\n";
        std::cout << "3\n";
        std::cout << "3\n";
        return 0;
    }
    if (n == 1) {
        std::cout << "YES\n";
        std::cout << 2 * a[0] << "\n";
        std::cout << 2 * a[0] << "\n";
        std::cout << 3 * a[0] << "\n";
        return 0;
    }
    if (a.back() > a[0] * 3) {
        std::cout << "NO\n";
        return 0;
    }
    if (n == 2) {
        std::cout << "YES\n";
        std::cout << 3 * a[0] << "\n";
        std::cout << 4 * a[0] - a[1] << "\n";
        return 0;
    }
    if (n == 3) {
        if (a[2] == 3 * a[0]) {
            std::cout << "YES\n";
            std::cout << 4 * a[0] - a[1] << "\n";
        } else if (a[1] + a[2] == 4 * a[0]) {
            std::cout << "YES\n";
            std::cout << 3 * a[0] << "\n";
        } else if (a[2] % 3 == 0 && a[0] + a[1] == a[2] / 3 * 4) {
            std::cout << "YES\n";
            std::cout << a[2] / 3 << "\n";
        } else {
            std::cout << "NO\n";
        }
        return 0;
    }
    if (a[3] == a[0] * 3 && a[1] + a[2] == 4 * a[0]) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return 0;
}