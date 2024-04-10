#include <bits/stdc++.h>

using int64 = long long;

const int C = 5;
const int N = 1000005;

int T, n, x, y, z;
int c[C];
int a[C][N];

std::string s;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> s;
            memset(c, 0, sizeof(c));
            for (int j = 0; j < s.size(); ++j) ++c[s[j] - 'a'];
            for (int j = 0; j < C; ++j) a[j][i] = c[j] * 2 - s.size();
        }
        x = y = z = 0;
        for (int i = 0; i < C; ++i) {
            std::sort(a[i] + 1, a[i] + n + 1, [](int x, int y) {
                return x > y;
            });
            x = y = 0;
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] <= 0 && x + a[i][j] <= 0) break;
                x += a[i][j], ++y;
            }
            z = std::max(z, y);
        }
        std::cout << z << '\n';
    }
    return 0;
}