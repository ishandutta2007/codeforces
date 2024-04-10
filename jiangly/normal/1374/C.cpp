#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::string s;
        std::cin >> n >> s;
        int mn = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++b;
            } else {
                --b;
            }
            mn = std::min(mn, b);
        }
        std::cout << -mn << "\n";
    }
    return 0;
}