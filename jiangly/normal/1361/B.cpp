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
#include <iomanip>
constexpr int P = 1000000007;
constexpr long long INF = 1e9;
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
    int t;
    std::cin >> t;
    while (t--) {
        int n, p;
        std::cin >> n >> p;
        std::vector<int> k(n);
        for (int i = 0; i < n; ++i)
            std::cin >> k[i];
        std::sort(k.begin(), k.end());
        if (p == 1) {
            std::cout << (n & 1) << "\n";
        } else {
            int suma = power(p, k[n - 1]), sumb = 0;
            int a = 1, b = k[n - 1];
            for (int i = n - 2; i >= 0; --i) {
                int e = b - k[i], x = p;
                while (e) {
                    if (e & 1) {
                        if (a < 0) {
                            a = -std::min(INF, -1ll * a * x);
                        } else {
                            a = std::min(INF, 1ll * a * x);
                        }
                    }
                    x = std::min(INF, 1ll * x * x);
                    e >>= 1;
                }
                b = k[i];
                if (a > 0) {
                    --a;
                    sumb = (sumb + power(p, k[i])) % P;
                } else {
                    ++a;
                    suma = (suma + power(p, k[i])) % P;
                }
            }
            std::cout << (suma - sumb + P) % P << "\n";
        }
    }
    return 0;
}