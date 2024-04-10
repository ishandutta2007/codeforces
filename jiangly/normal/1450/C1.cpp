#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::string> s(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> s[i];
        }
        int cnt[2][3] {};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == 'O') {
                    ++cnt[0][(i + j) % 3];
                }
                if (s[i][j] == 'X') {
                    ++cnt[1][(i + j) % 3];
                }
            }
        }
        int x = 0;
        for (int i = 1; i < 3; ++i) {
            if (cnt[0][i] + cnt[1][(i + 1) % 3] < cnt[0][x] + cnt[1][(x + 1) % 3]) {
                x = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == 'O' && (i + j) % 3 == x) {
                    s[i][j] = 'X';
                }
                if (s[i][j] == 'X' && (i + j) % 3 == (x + 1) % 3) {
                    s[i][j] = 'O';
                }
            }
            std::cout << s[i] << "\n";
        }
    }
    
    return 0;
}