#include <bits/stdc++.h>

inline std::string Add() { return std::string(); }

template <typename... Args>
inline std::string Add(char a, Args... args) {
    return a + Add(args...);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        bool Flag = false;
        std::set<std::string> Set, Set3;
        while (n--) {
            std::string s;
            std::cin >> s;
            if (Flag) continue;
            if (s.length() == 1) {
                Flag = true;
            } else if (s.length() == 2) {
                Set.insert(s);
                Flag |= Set.count(Add(s[1], s[0]));
                Flag |= Set3.count(Add(s[1], s[0]));
            } else {
                Set.insert(s), Set3.insert(s.substr(0, 2));
                Flag |= Set.count(Add(s[2], s[1]));
                Flag |= Set.count(Add(s[2], s[1], s[0]));
            }
        }
        std::cout << (Flag ? "YES" : "NO") << std::endl;
    }
    return 0;
}