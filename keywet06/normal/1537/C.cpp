#include <bits/stdc++.h>

const int N = 200005;

int T, n, p, m;
int a[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::sort(a + 1, a + n + 1);
        if (n == 2) {
            std::cout << a[1] << ' ' << a[2] << std::endl;
            continue;
        }
        m = 1000000000;
        for (int i = 1; i < n; ++i) {
            if (a[i + 1] - a[i] < m) {
                m = a[i + 1] - a[i];
                p = i;
            }
        }
        for (int i = p + 1; i <= n; ++i) std::cout << a[i] << ' ';
        for (int i = 1; i <= p; ++i) std::cout << a[i] << ' ';
        std::cout << std::endl;
    }
    return 0;
}