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
        if (n == 1) {
            std::cout << "1\n";
        } else if (n == 2) {
            std::cout << "-1\n";
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int x = (j - i + n) % n;
                    std::cout << x * n + i + 1 << " \n"[j == n - 1];
                }
            }
        }
    }
    return 0;
}