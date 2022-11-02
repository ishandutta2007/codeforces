#include <bits/stdc++.h>

const int N = 10005;

char s[N], t[N];

int n, m, c, x, y;
int f[N][N];

inline int &mid(int &x, int y) { return x < y ? x : (x = y); }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> s + 1 >> t + 1, n = strlen(s + 1), m = strlen(t + 1);
    memset(f, 1, sizeof(f)), f[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        x = s[i + 1] == '.' ? n + 1 : i + 1, c = 0;
        while (x <= n && (c += s[x] == '.' ? -1 : 1)) ++x;
        for (int j = 0, u; u = f[i][j], j <= i && j <= m; ++j) {
            mid(f[i + 1][j], u + 1), mid(f[x][j], u);
            if (s[i + 1] == t[j + 1]) mid(f[i + 1][j + 1], u);
        }
    }
    std::cout << f[n][m] << std::endl;
    return 0;
}