#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2E7;

std::vector<int> primes;

bool isprime[N + 1];

int cnt[N + 1];

i64 dp[N + 1];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    primes.reserve(1270607);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::fill(isprime + 2, isprime + N + 1, true);
    for (int i = 2; i <= N; i++) {
        if (isprime[i]) {
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > N) {
                break;
            }
            isprime[i * p] = false;
            if (i % p == 0) {
                break;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    for (auto p : primes) {
        for (int i = N / p; i > 0; i--) {
            cnt[i] += cnt[i * p];
        }
    }
    
    i64 res = 0;
    for (int i = 1; i <= N; i++) {
        res = std::max(res, dp[i] + 1LL * cnt[i] * i);
        for (auto p : primes) {
            if (i * p > N) {
                break;
            }
            dp[i * p] = std::max(dp[i * p], dp[i] + 1LL * i * (cnt[i] - cnt[i * p]));
        }
    }
    
    std::cout << res << '\n';
    
    return 0;
}