#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        int a[2] = {};
        for (int i = 0; i < n; i++) {
            std::string s;
            std::cin >> s;
            for (int j = 0; j < m; j++) {
                if (s[j] != '.') {
                    a[(s[j] == 'R') ^ ((i + j) % 2)] = 1;
                }
            }
        }
        if (a[0] && a[1]) {
            std::cout << "NO\n";
            continue;
        }
        std::cout << "YES\n";
        int x = !a[1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << "RW"[(i + j + x) % 2];
            }
            std::cout << "\n";
        }
    }
    return 0;
}