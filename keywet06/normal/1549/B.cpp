#include <bits/stdc++.h>

using int64 = long long;

const int B = 2;
const int N = 200005;

int T, n, x, y, z, ans;
int f[N][B][B];

std::string s, t;

inline int &mad(int &x, int y) { return x = std::max(x, y); }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> t >> s;
        t = '0' + t + '0', s = '0' + s + '0';
        for (int i = 0; i <= n + 1; ++i) s[i] -= '0', t[i] -= '0';
        f[1][0][1] = s[1] && t[2];
        f[1][1][0] = s[1] && !t[1];
        for (int i = 2; i <= n; ++i) {
            f[i][0][0] = std::max(f[i - 1][0][0], f[i - 1][1][0]);
            f[i][1][0] = std::max(f[i - 1][0][1], f[i - 1][1][1]);
            f[i][0][1] = f[i][1][1] = 0;
            if (!s[i]) continue;
            if (!t[i]) {
                mad(f[i][1][0], std::max(f[i - 1][1][0], f[i - 1][0][0]) + 1);
            }
            if (t[i - 1]) {
                mad(f[i][0][0], f[i - 1][0][0] + 1);
                mad(f[i][1][0], f[i - 1][0][1] + 1);
            }
            if (t[i + 1]) {
                mad(f[i][0][1], std::max(f[i - 1][1][0], f[i - 1][0][0]) + 1);
                mad(f[i][1][1], std::max(f[i - 1][1][1], f[i - 1][0][1]) + 1);
            }
        }
        std::cout << std::max(f[n][0][0], f[n][1][0]) << '\n';
    }
    return 0;
}