#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = std::sqrt(1e9);
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<int> isprime(N + 1), primes;
    std::fill(isprime.begin() + 2, isprime.end(), 1);
    for (int i = 2; i <= N; i++) {
        if (isprime[i]) {
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > N) {
                continue;
            }
            isprime[i * p] = 0;
            if (i % p == 0) {
                continue;
            }
        }
    }
    auto count = [&](int n) {
        int ans = 0;
        for (auto p : primes) {
            if (p * p > n) {
                continue;
            }
            while (n % p == 0) {
                ans++;
                n /= p;
            }
        }
        if (n > 1) {
            ans++;
        }
        return ans;
    };
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, k;
        std::cin >> a >> b >> k;
        if (k == 1) {
            if (a == b) {
                std::cout << "NO\n";
            } else if (a % b == 0 || b % a == 0) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
            continue;
        }
        int cnt = count(a) + count(b);
        std::cout << (k <= cnt ? "YES" : "NO") << "\n";
    }
    return 0;
}