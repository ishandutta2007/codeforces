#include <bits/stdc++.h>

const int N = 1000005;

int T, n, x, y;
int a[N];

inline int sol(int x, int y, int z) {
    return !(a[x] <= a[y] && a[y] <= a[z] || a[x] >= a[y] && a[y] >= a[z]);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        x = (n > 2 && sol(1, 2, 3)) + n + n - 1;
        for (int i = 4; i <= n; ++i) {
            x += sol(i - 2, i - 1, i);
            x += sol(i - 2, i - 1, i) && sol(i - 3, i - 2, i - 1) &&
                 sol(i - 3, i - 2, i) && sol(i - 3, i - 1, i);
        }
        std::cout << x << std::endl;
    }
    return 0;
}