#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <chrono>
#include <queue>
#include <set>
#include <cassert>
#include <random>
#include <chrono>
#include <complex>
#include <cstring>
#include <map>
constexpr int P = 998244353;
int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = 1ll * res * a % P;
        a = 1ll * a * a % P;
        b >>= 1;
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> fac(n + 1), invFac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = 1ll * fac[i - 1] * i % P;
    invFac[n] = power(fac[n], P - 2);
    for (int i = n; i > 0; --i)
        invFac[i - 1] = 1ll * invFac[i] * i % P;
    int ans = 0; 
    for (int i = 1; i <= n; ++i) {
        int m = n / i - 1;
        if (m >= k - 1)
            ans = (ans + 1ll * fac[m] * invFac[k - 1] % P * invFac[m - k + 1]) % P;
    }
    std::cout << ans << "\n";
    return 0;
}