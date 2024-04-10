#include <bits/stdc++.h>

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
        int ans = 0;
        for (int i = 0; i < n; ++i) ans += (s[i] == s[(i + 1) % n]);
        std::cout << ans / 2 << "\n";
    }
    
    return 0;
}