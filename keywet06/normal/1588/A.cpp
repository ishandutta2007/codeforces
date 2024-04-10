#include <bits/stdc++.h>

const int N = 105;

int T, n, f;
int a[N], b[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> b[i];
        std::sort(a, a + n), std::sort(b, b + n), f = 1;
        for (int i = 0; i < n; ++i) {
            f &= a[i] + 1 == b[i] || a[i] == b[i];
        }
        std::cout << (f ? "YES" : "NO") << '\n';
    }
    return 0;
}