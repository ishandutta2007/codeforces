#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int x;
        std::cin >> x;
        int n = s.length();
        std::string w(n, '0');
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (i >= x && w[i - x] == '1') {
                    w = "-1";
                    break;
                }
            } else {
                if (i >= x && w[i - x] == '1') {
                    continue;
                } else if (i >= x && (i < 2 * x || s[i - 2 * x] == '1')) {
                    w[i - x] = '1';
                } else if (i + x >= n) {
                    w = "-1";
                    break;
                } else {
                    w[i + x] = '1';
                }
            }
        }
        std::cout << w << "\n";
    }
    return 0;
}