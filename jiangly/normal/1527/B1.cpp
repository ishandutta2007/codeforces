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
        std::string s;
        std::cin >> s;
        if (n % 2 == 1 && s[(n - 1) / 2] == '0') {
            if (std::count(s.begin(), s.end(), '0') == 1) {
                std::cout << "BOB\n";
            } else if (std::count(s.begin(), s.end(), '0') == 2) {
                std::cout << "DRAW\n";
            } else {
                std::cout << "ALICE\n";
            }
            continue;
        }
        int count = 0;
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                count++;
            }
        }
        if (count == 1 && n % 2 == 1 && s[(n - 1) / 2] == '0') {
            std::cout << "DRAW\n";
        } else if (count == 0 || (n % 2 == 1 && s[(n - 1) / 2] == '0' && std::count(s.begin(), s.end(), '0') == 1)) {
            std::cout << "BOB\n";
        } else {
            std::cout << "ALICE\n";
        }
    }
    return 0;
}