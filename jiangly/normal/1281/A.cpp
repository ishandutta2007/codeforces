#include <iostream>
#include <string>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        if (s.substr(s.length() - 2, 2) == "po") {
            std::cout << "FILIPINO\n";
        } else if (s.length() >= 5 && s.substr(s.length() - 5, 5) == "mnida") {
            std::cout << "KOREAN\n";
        } else {
            std::cout << "JAPANESE\n";
        }
    }
    return 0;
}