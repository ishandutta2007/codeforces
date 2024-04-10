#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int s[4];
        for (int i = 0; i < 4; i++) {
            std::cin >> s[i];
        }
        if (std::max(s[0], s[1]) < std::min(s[2], s[3]) || std::max(s[2], s[3]) < std::min(s[0], s[1])) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
    return 0;
}