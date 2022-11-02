#include <bits/stdc++.h>

const int N = 1e3 + 23;

char str[N][N];

int n, m, p, T;

void solve() {}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) std::cin >> str[i] + 1;
        for (int i = 1 + (m % 3 == 0); i <= m;) {
            for (int j = 1; j <= n; ++j) str[j][i] = 'X';
            if ((i += 3) > m) break;
            p = 2 - (n == 1 || (str[2][i - 1] != 'X' && str[2][i - 2] != 'X'));
            str[p][i - 1] = str[p][i - 2] = 'X';
        }
        for (int i = 1; i <= n; ++i) std::cout << str[i] + 1 << '\n';
    }
    return 0;
}