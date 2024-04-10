#include <bits/stdc++.h>

std::string s;

bool check() {
    if (s.size() % 2 == 0) { return false; }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != '0') { return false; }
    }
    return s[0] == '1';
}

int main() {
    std::cin >> s;
    if (s == "0") {
        std::cout << 0 << std::endl; return 0;
    }
    std::cout << (check() ? s.size() / 2 : (s.size() + 1) / 2) << std::endl;
    return 0;
}