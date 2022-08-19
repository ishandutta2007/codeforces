#include <bits/stdc++.h>
constexpr int P = 998244353;
constexpr int A[16] = {0, 0, 0, 24, 4, 240, 204, 1316, 2988, 6720, 26200, 50248, 174280, 436904, 1140888, 3436404};
constexpr int F[16] = {P - 1, P - 4, P - 4, P - 16, 15, P - 44, 26, P - 48, P - 12, 4, P - 10, 16, P - 1, 8, 4, 0};
void mul(int *a, int *b) {
    int64_t tmp[31] = {};
    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j)
            tmp[i + j] += 1ll * a[i] * b[j];
    for (int i = 0; i <= 30; ++i)
        tmp[i] %= P;
    for (int i = 30; i >= 16; --i) {
        tmp[i] %= P;
        for (int j = 0; j < 16; ++j)
            tmp[i - 16 + j] += F[j] * tmp[i];
    }
    for (int i = 0; i < 16; ++i)
        a[i] = tmp[i] % P;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int f[16] = {}, g[16] = {};
    f[0] = 1;
    g[1] = 1;
    for (; n; n >>= 1, mul(g, g))
        if (n & 1)
            mul(f, g);
    int64_t ans = 0;
    for (int i = 0; i < 16; ++i)
        ans += 1ll * f[i] * A[i];
    std::cout << ans % P << "\n";
    return 0;
}