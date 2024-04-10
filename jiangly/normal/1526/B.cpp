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
        int x;
        std::cin >> x;
        bool ans = false;
        for (int i = 0; i < 11; i++) {
            if (111 * i <= x && (x - 111 * i) % 11 == 0) {
                ans = true;
            }
        }
        if (ans) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}