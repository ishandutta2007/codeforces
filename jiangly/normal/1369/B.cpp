#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        int i = 0, j = n;
        while (i < n && s[i] == '0')
            ++i;
        while (j > 0 && s[j - 1] == '1')
            --j;
        if (i == j) {
            std::cout << s << "\n";
        } else {
            std::cout << s.substr(0, i) + '0' + s.substr(j) << "\n";
        }
    }
    return 0;
}