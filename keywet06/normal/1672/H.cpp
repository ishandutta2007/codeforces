#include <bits/stdc++.h>

const int N = 200005;

int n, q;
int a[N], f[2][N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        char tmp;
        std::cin >> tmp;
        a[i] = tmp - '0';
    }
    for (int i = 2; i <= n; ++i) {
        if (a[i] == a[i - 1]) f[a[i]][i] = 1;
        f[0][i] += f[0][i - 1];
        f[1][i] += f[1][i - 1];
    }
    for (int i = 1; i <= q; ++i) {
        int L, R;
        std::cin >> L >> R;
        int x = f[0][R] - f[0][L];
        int y = f[1][R] - f[1][L];
        std::cout << std::max(x, y) + 1 << '\n';
    }
    return 0;
}