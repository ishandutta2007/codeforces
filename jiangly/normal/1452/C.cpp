#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int s1 = 0, s2 = 0, m1 = 0, m2 = 0;
        int ans = 0;
        std::string s;
        std::cin >> s;
        for (auto c : s) {
            if (c == '(') {
                ++s1;
            } else if (c == ')') {
                --s1;
                m1 = std::min(m1, s1);
                ++ans;
            } else if (c == '[') {
                ++s2;
            } else {
                --s2;
                m2 = std::min(m2, s2);
                ++ans;
            }
        }
        std::cout << ans + m1 + m2 << "\n";
    }
    
    return 0;
}