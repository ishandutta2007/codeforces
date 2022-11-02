#include <bits/stdc++.h>

using int64 = long long;

int n, m, q, x[100010], a[1000], p;

inline int Pow(int a, int b, int q) {
    if (!b) return 1;
    int c = Pow(a, b >> 1, q);
    c = std::min((int64)c * c % q + q, (int64)c * c);
    if (b & 1) c = std::min((int64)c * a % q + q, (int64)c * a);
    return c;
}

inline int solve(int i, int j, int k) {
    if (i > j) return 1;
    if (k == p) return std::min(x[i], 2);
    return Pow(x[i], solve(i + 1, j, k + 1), a[k]);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int i, j, k;
    std::cin >> n >> q;
    for (i = 1; i <= n; ++i) std::cin >> x[i];
    std::cin >> m;
    a[1] = q;
    for (p = 2; a[p - 1] > 1; ++p) {
        for (k = a[p - 1], i = 2, j = 1; i * i <= k; ++i) {
            if (k % i == 0) {
                j *= i - 1, k /= i;
                while (k % i == 0) j *= i, k /= i;
            }
        }
        if (k > 1) j *= k - 1;
        a[p] = j;
    }
    --p;
    while (m--) std::cin >> i >> j, std::cout << solve(i, j, 1) % q << '\n';
    return 0;
}