#include <bits/stdc++.h>

using int64 = long long;

const int64 N = 1e6 + 10;
const int64 G = 31;

int64 s, bi[N], ci[N], n, A[N], cnt[G];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> bi[i], s += bi[i];
    for (int i = 1; i <= n; ++i) std::cin >> ci[i], s += ci[i];
    if (s % (2 * n)) return std::cout << -1 << '\n', 0;
    s = s / (2 * n);
    for (int i = 1; i <= n; ++i) {
        A[i] = bi[i] + ci[i] - s;
        if (A[i] % n) return std::cout << -1 << '\n', 0;
        A[i] /= n;
        for (int j = 0; j < G; ++j) {
            if (A[i] & (1ll << j)) ++cnt[j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        int64 tb = 0;
        for (int j = 0; j < G; ++j) {
            if ((A[i] & (1ll << j))) tb += cnt[j] * (1ll << j);
        }
        if (tb != bi[i]) return std::cout << -1 << '\n', 0;
    }
    for (int i = 1; i <= n; ++i) std::cout << A[i] << ' ';
    std::cout << '\n';
    return 0;
}