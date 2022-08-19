#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int odd = 0;
        for (int i = 0; i < 2 * n; i++) {
            int x;
            std::cin >> x;
            if (x % 2 == 1) {
                odd++;
            }
        }
        if (odd == n) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}