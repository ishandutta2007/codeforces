#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, q;
        std::cin >> n >> q;
        std::string s;
        std::cin >> s;
        while (q--) {
            int l, r;
            std::cin >> l >> r;
            --l;
            if (std::count(s.begin(), s.begin() + l, s[l]) || std::count(s.begin() + r, s.end(), s[r - 1])) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
    }
    
    return 0;
}