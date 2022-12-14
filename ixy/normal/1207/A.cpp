#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int a, b, c, x, y;

int main() {
    for (int T = read(); T; T--) {
        a = read(); b = read(); c = read();
        x = read(); y = read(); a /= 2;
        int ans = 0;
        for (int i = 0; i <= b; i++) {
            for (int j = 0; j <= c; j++) {
                if (i + j <= a) {
                    ans = std::max(ans, i * x + j * y);
                }
            }
        } printf("%d\n", ans);
    }
    return 0;
}