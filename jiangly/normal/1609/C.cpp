#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1E6;

bool isprime[N + 1];
std::vector<int> primes;

void solve() {
    int n, e;
    std::cin >> n >> e;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a[i] = x == 1 ? 0 : isprime[x] ? 1 : 2;
    }
    
    
    i64 ans = 0;
    
    for (int c = 0; c < e; c++) {
        std::vector<int> b;
        for (int i = c; i < n; i += e) {
            b.push_back(a[i]);
        }
        int sum = 0;
        for (int i = 0, j = 0; i < int(b.size()); i++) {
            sum += b[i];
            while (sum > 1) {
                sum -= b[j];
                j++;
            }
            ans += std::max(0, i - j);
        }
        sum = 0;
        for (int i = 0, j = 0; i < int(b.size()); i++) {
            sum += b[i];
            while (sum > 0) {
                sum -= b[j];
                j++;
            }
            ans -= std::max(0, i - j);
        }
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
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
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}