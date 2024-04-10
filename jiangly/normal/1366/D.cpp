#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
constexpr int N = 1e7;
int minp[N + 1];
std::vector<int> primes;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int i = 2; i <= N; ++i) {
        if (!minp[i]) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > N)
                break;
            minp[i * p] = p;
            if (i % p == 0)
                break;
        }
    }
    int n;
    std::cin >> n;
    std::vector<int> d1(n, -1), d2(n, -1);
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        std::vector<int> p;
        for (int x = a; x > 1; x /= minp[x])
            p.push_back(minp[x]);
        if (p[0] != p.back()) {
            int j = 0;
            d1[i] = 1;
            while (p[0] == p[j]) {
                ++j;
                d1[i] *= p[0];
            }
            d2[i] = a / d1[i];
        }
    }
    for (int i = 0; i < n; ++i)
        std::cout << d1[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; ++i)
        std::cout << d2[i] << " \n"[i == n - 1];
    return 0;
}