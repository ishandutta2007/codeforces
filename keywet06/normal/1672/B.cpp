#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        std::string s;
        std::cin >> s;
        int Sum = 0;
        char last;
        bool Okay = true;
        for (char ch : s) {
            last = ch;
            if (ch == 'A') ++Sum;
            if (ch == 'B') --Sum;
            if (!(Okay &= Sum >= 0)) break;
        }
        Okay &= last == 'B';
        std::cout << (Okay ? "YES" : "NO") << '\n';
    }
    return 0;
}