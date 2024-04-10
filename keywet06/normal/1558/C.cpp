#include <bits/stdc++.h>

const int N = 10005;

int T, n, c;
int p[N], q[N], u[N];

void swap(int x) {
    u[++c] = x;
    for (int i = 1; i + i < x; ++i) {
        std::swap(p[i], p[x - i + 1]);
        std::swap(q[p[i]], q[p[x - i + 1]]);
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> p[i], q[p[i]] = i;
        c = 0;
        for (int i = 2; i <= n; ++++i) {
            if (p[i] & 1) c = -1;
        }
        if (c == -1) {
            std::cout << c << '\n';
            continue;
        }
        while (n > 1) {
            swap(q[n]), swap(q[n - 1] - 1);
            swap(q[n - 1] + 1), swap(q[n]);
            swap(n), ----n;
        }
        std::cout << c << '\n';
        for (int i = 1; i <= c; ++i) std::cout << u[i] << " \n"[i == c];
    }
    return 0;
}