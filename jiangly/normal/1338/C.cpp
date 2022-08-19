#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
constexpr long long A[] = {0, 2, 3, 1};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        --n;
        long long k = n / 3;
        long long s = 1;
        while (k >= s) {
            k -= s;
            s *= 4;
        }
        long long a = s + k;
        long long b = 2 * s;
        for (int i = 0; (1ll << i) < s; i += 2)
            b += A[k >> i & 3] << i;
        if (n % 3 == 0) {
            std::cout << a << "\n";
        } else if (n % 3 == 1) {
            std::cout << b << "\n";
        } else {
            std::cout << (a ^ b) << "\n";
        }
    }
    return 0;
}