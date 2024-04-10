#include <iostream>
#include <numeric>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long x;
    std::cin >> x;
    long long ans = 1;
    for (long long i = 1; i * i <= x; ++i)
        if (x % i == 0 && std::gcd(i, x / i) == 1)
            ans = i;
    std::cout << ans << " " << x / ans << "\n";
    return 0;
}