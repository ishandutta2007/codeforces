#include <bits/stdc++.h>

constexpr int P = 998244353;

int power(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = 1ll * a * a % P) {
        if (b & 1) {
            res = 1ll * res * a % P;
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) std::cin >> c[i];
    std::sort(c.begin(), c.end(), std::greater<>());
    std::vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) sum[i + 1] = (sum[i] + c[i]) % P;
    int inv = power(n, P - 2) % P;
    for (int k = 1; k <= n; ++k) {
        int ans = 0;
        for (int i = 0; i * k < n; ++i) {
            ans = (ans +
                   1ll * i * (sum[std::min(n, (i + 1) * k)] - sum[i * k] + P)) %
                  P;
        }
        std::cout << 1ll * inv * ans % P << " \n"[k == n];
    }
    return 0;
}