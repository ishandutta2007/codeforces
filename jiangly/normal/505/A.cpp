#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    for (int i = 0; i <= int(s.size()); i++) {
        for (auto c = 'a'; c <= 'z'; c++) {
            auto t = s.substr(0, i) + c + s.substr(i);
            auto rt = t;
            std::reverse(t.begin(), t.end());
            if (t == rt) {
                std::cout << t << "\n";
                return 0;
            }
        }
    }
    std::cout << "NA\n";
    return 0;
}