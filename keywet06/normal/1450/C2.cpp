#include <bits/stdc++.h>

const int N = 305;
int te, n;
std::string s[N];

inline void solve() {
    std::cin >> n;
    int cnt[3][2] = {{0, 0}, {0, 0}, {0, 0}};
    int k = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        for (int j = 0; j < n; ++j) {
            char c = s[i][j];
            int val = (i + j) % 3;
            if (c == 'X') ++cnt[val][0], ++k;
            if (c == 'O') ++cnt[val][1], ++k;
        }
    }
    for (int d = 0; d < 3; ++d) {
        for (int d2 = 0; d2 < 3; ++d2) {
            if (d == d2) continue;
            if (cnt[d][0] + cnt[d2][1] <= k / 3) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if ((i + j) % 3 == d && s[i][j] == 'X') s[i][j] = 'O';
                        if ((i + j) % 3 == d2 && s[i][j] == 'O') s[i][j] = 'X';
                    }
                    std::cout << s[i] << '\n';
                }
                return;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> te;
    while (te--) solve();
    return 0;
}