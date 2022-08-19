#include <iostream>
#include <string>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s, t;
        std::cin >> s >> t;
        char minChar = 'z';
        int j = -1;
        for (int i = s.length() - 1; i >= 0; --i) {
            minChar = std::min(minChar, s[i]);
            if (s[i] != minChar)
                j = i;
        }
        if (j != -1)
            std::swap(s[j], *std::min_element(s.rbegin(), s.rend() - j));
        if (s < t) {
            std::cout << s << "\n";
        } else {
            std::cout << "---\n";
        }
    }
    return 0;
}