#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n;
long long x, y, f[2][N];

std::string str;

int main() {
    for (int T = read(); T; T--) {
        n = read(); x = read(); y = read();
        std::cin >> str; str = " " + str;
        f[0][0] = x * n + y * (n + 1); f[1][0] = 1e18;
        for (int i = 1; i <= n; i++) {
            f[0][i] = f[0][i - 1]; f[1][i] = f[1][i - 1];
            if (str[i] == '0') {
                f[0][i] = std::min(f[0][i], f[1][i] + x);
                f[1][i] = std::min(f[1][i], f[0][i] + x);
            }
            f[1][i] += y;
            if (str[i] == '1') { f[0][i] = 1e18; }
        }
        printf("%I64d\n", f[0][n]);
    }
    return 0;
}