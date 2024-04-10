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
        int count[26] {};
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        char last = '?';
        bool bad = false;
        for (auto ch : s) {
            if (count[ch - 'A'] && last != ch) {
                bad = true;
            }
            count[ch - 'A'] = 1;
            last = ch;
        }
        if (bad) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
    return 0;
}