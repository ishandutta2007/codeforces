#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int n = s.length() / 2;
        for (int i = 0; i < n; ++i)
            std::cout << s[2 * i];
        std::cout << s.back() << "\n";
    }
    return 0;
}