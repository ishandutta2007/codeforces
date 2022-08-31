#include <iostream>
#include <algorithm>
int t;
std::string s;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> s;
        int n = s.length();
        int l = 0, r = n;
        while (l < n && s[l] == '0')
            ++l;
        while (r > l && s[r - 1] == '0')
            --r;
        std::cout << r - l - std::count(s.begin(), s.end(), '1') << "\n";
    }
    return 0;
}