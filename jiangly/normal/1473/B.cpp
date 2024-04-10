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
        std::string a, b;
        std::cin >> a >> b;
        int d = std::gcd(a.length(), b.length());
        std::string a1, b1;
        for (int i = 0; i < int(b.length()) / d; i++) {
            a1 += a;
        }
        for (int i = 0; i < int(a.length()) / d; i++) {
            b1 += b;
        }
        if (a1 == b1) {
            std::cout << a1 << "\n";
        } else {
            std::cout << "-1\n";
        }
    }
    return 0;
}