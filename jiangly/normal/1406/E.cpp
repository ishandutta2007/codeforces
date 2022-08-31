#include <bits/stdc++.h>
int main() {
    int n;
    std::cin >> n;
    int sq = std::sqrt(n);
    std::vector<bool> isprime(n + 1);
    for (int i = 2; i <= n; ++i)
        isprime[i] = true;
    std::vector<int> small, large;
    for (int i = 2; i * i <= n; ++i) {
        if (!isprime[i])
            continue;
        small.push_back(i);
        for (int j = i * i; j <= n; j += i)
            isprime[j] = false;
    }
    for (int i = sq + 1; i <= n; ++i)
        if (isprime[i])
            large.push_back(i);
    for (auto x : small) {
        std::cout << "B " << x << std::endl;
        int ret;
        std::cin >> ret;
    }
    int ans = 1;
    for (auto x : small) {
        int c = 1;
        int ret = 1;
        while (ret > 0) {
            c *= x;
            if (c > n) {
                ret = 0;
            } else {
                std::cout << "A " << c << std::endl;
                std::cin >> ret;
            }
        }
        ans *= c / x;
    }
    std::cout << "A " << 1 << std::endl;
    int res;
    std::cin >> res;
    while (!large.empty()) {
        int t = large.size();
        int m = t / 2;
        for (int i = m; i < t; ++i) {
            std::cout << "B " << large[i] << std::endl;
            int ret;
            std::cin >> ret;
            if (ret > 1) {
                ans *= large[i];
                std::cout << "C " << ans << std::endl;
                return 0;
            }
        }
        std::cout << "A " << 1 << std::endl;
        int nres;
        std::cin >> nres;
        if (res - nres != t - m) {
            for (int i = m; i < t; ++i) {
                std::cout << "A " << large[i] << std::endl;
                int ret;
                std::cin >> ret;
                if (ret > 0) {
                    std::cout << "C " << large[i] << std::endl;
                    return 0;
                }
            }
        }
        res = nres;
        large.resize(m);
    }
    std::cout << "C " << ans << std::endl;
    return 0;
}