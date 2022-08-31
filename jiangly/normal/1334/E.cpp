#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
constexpr int P = 998244353;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long d;
    std::cin >> d;
    std::vector<long long> factors;
    for (long long i = 2; i * i <= d; ++i) {
        if (d % i == 0) {
            factors.push_back(i);
            while (d % i == 0)
                d /= i;
        }
    }
    if (d > 1)
        factors.push_back(d);
    int C[60][60] = {};
    for (int i = 0; i < 60; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
    }
    int q;
    std::cin >> q;
    auto count = [&](long long a, long long b) {
        int res = 1, sum = 0;
        for (auto p : factors) {
            int x = 0;
            for (; a % p == 0; a /= p)
                ++x;
            for (; b % p == 0; b /= p)
                --x;
            sum += x;
            res = 1ll * res * C[sum][x] % P;
        }
        return res;
    };
    while (q--) {
        long long u, v;
        std::cin >> u >> v;
        long long g = std::gcd(u, v);
        std::cout << 1ll * count(u, g) * count(v, g) % P << "\n";
    }
    return 0;
}