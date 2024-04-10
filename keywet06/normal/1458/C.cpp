#include <bits/stdc++.h>

const int N = 1005;

int T, n, m;
int d[N], e[N], f[N];
int a[N][N], b[N][N];

std::string s;

inline int fit(int x) { return ((x - 1) % n + n) % n + 1; }
inline int num(int x) { return fit(f[d[x]] + e[x]); }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) std::cin >> a[i][j];
        }
        std::cin >> s;
        d[1] = 1, d[2] = 2, d[3] = 3, e[1] = e[2] = e[3] = 0;
        for (char c : s) {
            if (c == 'L') --e[2];
            if (c == 'R') ++e[2];
            if (c == 'U') --e[1];
            if (c == 'D') ++e[1];
            if (c == 'I') std::swap(d[2], d[3]), std::swap(e[2], e[3]);
            if (c == 'C') std::swap(d[1], d[3]), std::swap(e[1], e[3]);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[1] = i, f[2] = j, f[3] = a[i][j];
                b[num(1)][num(2)] = num(3);
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) std::cout << b[i][j] << " \n"[j == n];
        }
        std::cout << '\n';
    }
    return 0;
}