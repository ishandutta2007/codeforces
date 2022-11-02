#include <bits/stdc++.h>

using int64 = long long;

const int N = 1000005;

int T, n, k, x, y, z, d, e, f;
int a[N], b[N], p[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    x = (1ull << 32) - 1;
    for (int i = 2; i <= n; ++i) {
        std::cout << "or 1 " << i << std::endl;
        std::cin >> a[i], x &= a[i];
    }
    for (int i = 2; i <= n; ++i) {
        std::cout << "and 1 " << i << std::endl;
        std::cin >> b[i], y |= b[i];
    }
    std::cout << "or 2 3" << std::endl;
    std::cin >> d;
    std::cout << "and 2 3" << std::endl;
    std::cin >> e;
    p[1] = x = y | (x & ~e);
    for (int i = 2; i <= n; ++i) p[i] = (x ^ a[i]) | (x & b[i]);
    std::sort(p + 1, p + n + 1);
    std::cout << "finish " << p[k] << std::endl;
    return 0;
}