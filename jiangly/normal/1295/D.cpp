#include <iostream>
#include <numeric>
int t;
long long a, m;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> a >> m;
        m /= std::gcd(a, m);
        long long x = m;
        for (long long i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                while (x % i == 0)
                    x /= i;
                m = m / i * (i - 1);
            }
        }
        if (x != 1)
            m = m / x * (x - 1);
        std::cout << m << "\n";
    }
    return 0;
}