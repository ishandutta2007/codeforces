#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, q;
        std::cin >> a >> b >> q;
        std::vector<int> sum(a * b + 1);
        for (int i = 0; i < a * b; ++i)
            sum[i + 1] = sum[i] + (i % a % b != i % b % a);
        auto query = [&](auto n) {
            return sum[a * b] * (n / (a * b)) + sum[n % (a * b)];
        };
        for (int i = 0; i < q; ++i) {
            long long l, r;
            std::cin >> l >> r;
            std::cout << query(r + 1) - query(l) << " \n"[i == q - 1];
        }
    }
    return 0;
}