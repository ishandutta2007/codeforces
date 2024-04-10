#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::cout << 3 * n << "\n";
        for (int i = 0; i < n; i += 2) {
            std::cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
            std::cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
            std::cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
            std::cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
            std::cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
            std::cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
        }
    }
    return 0;
}