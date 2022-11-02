#include <bits/stdc++.h>

const int N = 200005;

int T, n;
int a[N], ok[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        int lastr1 = 0, last1 = 0, numr1 = 0, num1 = 0, s = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i], s += a[i];
            if (a[i] == 1 && last1 < i - 1) {
                last1 = i, ++num1, ok[i] = 1;
            } else if (a[i] == -1 && lastr1 < i - 1) {
                lastr1 = i, ++numr1, ok[i] = -1;
            } else {
                ok[i] = 0;
            }
        }
        if (s == 0) {
            std::cout << n << '\n';
            for (int i = 1; i <= n; ++i) std::cout << i << ' ' << i << '\n';
        } else if (s & 1 || s > 0 && s / 2 > num1 || s < 0 && -s / 2 > numr1) {
            std::cout << -1 << '\n';
        } else if (s > 0) {
            std::cout << n - s / 2 << '\n';
            for (int i = 1; i <= n; ++i) {
                if (s > 0 && ok[i + 1] == 1) {
                    s -= 2, std::cout << i << ' ' << i + 1 << '\n', ++i;
                } else {
                    std::cout << i << ' ' << i << '\n';
                }
            }
        } else {
            std::cout << n + s / 2 << '\n';
            for (int i = 1; i <= n; ++i) {
                if (s < 0 && ok[i + 1] == -1) {
                    s += 2, std::cout << i << ' ' << i + 1 << '\n', ++i;
                } else {
                    std::cout << i << ' ' << i << '\n';
                }
            }
        }
    }
    return 0;
}