#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    
    for (int i = 0; i < 27; i++) {
        for (int j = i + 1; j < 27; j++) {
            if (s[i] == s[j]) {
                if (i + 1 == j) {
                    std::cout << "Impossible\n";
                    return 0;
                }
                int m = (i + j) / 2 + 1;
                std::rotate(s.begin(), s.begin() + m, s.end());
                std::cout << s.substr(0, 13) << "\n";
                auto t = s.substr(13);
                std::reverse(t.begin(), t.end());
                t.erase(t.begin() + t.find(s[j - m]));
                std::cout << t << "\n";
                return 0;
            }
        }
    }
    
    assert(false);
}