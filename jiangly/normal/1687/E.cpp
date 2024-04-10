#include <bits/stdc++.h>

using i64 = long long;

constexpr int M = 1E6;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<int> primes, minp(M + 1);
    for (int i = 2; i <= M; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > M) {
                break;
            }
            minp[i * p] = p;
            if (i % p == 0) {
                break;
            }
        }
    }
    
    int n;
    std::cin >> n;
    
    std::map<int, std::vector<int>> f;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        int x = a[i];
        while (x > 1) {
            int p = minp[x];
            f[p].push_back(i);
            while (x % p == 0) {
                x /= p;
            }
        }
    }
    
    std::vector<int> u{ 0, 1 };
    for (auto [p, v] : f) {
        int c = (a[0] % p == 0) + (a[1] % p == 0);
        if (c == 0) {
            continue;
        }
        std::vector<int> r(n);
        for (int i = 2; i < n; i++) {
            int x = a[i];
            while (x % p == 0) {
                x /= p;
                r[i]++;
            }
        }
        std::vector<int> q(n - 2);
        std::iota(q.begin(), q.end(), 2);
        std::sort(q.begin(), q.end(), [&](int i, int j) {
            return r[i] < r[j];
        });
        for (int i = 0; i < std::min(c, int(q.size())); i++) {
            u.push_back(q[i]);
        }
    }
    
    std::sort(u.begin(), u.end());
    u.erase(std::unique(u.begin(), u.end()), u.end());
    
    n = u.size();
    
    auto get = [&](int s) {
        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s >> i & s >> j & 1) {
                    ans = std::gcd(ans, 1LL * a[u[i]] * a[u[j]]);
                }
            }
        }
        return ans;
    };
    
    int mask = (1 << n) - 1;
    i64 A = get(mask);
    for (int s = 1; s < (1 << n); s++) {
        int c = __builtin_popcount(s);
        if (get(s) == A && c < __builtin_popcount(mask)) {
            mask = s;
        }
    }
    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        if (mask >> i & 1) {
            v.push_back(u[i]);
        }
    }
    u = v;
    n = u.size();
    
    assert(n <= 14);
    std::vector<int> coef(1 << n);
    int ans = 0;
    for (int s = 1; s < (1 << n); s++) {
        int c = __builtin_popcount(s);
        coef[s] += (c % 2 == 0 ? 1 : -1) * (c - 2);
        ans += std::abs(coef[s]);
    }
    std::cout << ans << "\n";
    for (int s = 1; s < (1 << n); s++) {
        while (coef[s] != 0) {
            if (coef[s] > 0) {
                std::cout << "0 ";
                coef[s]--;
            } else {
                std::cout << "1 ";
                coef[s]++;
            }
            int c = __builtin_popcount(s);
            std::cout << c;
            for (int i = 0; i < n; i++) {
                if (s >> i & 1) {
                    std::cout << " " << u[i] + 1;
                }
            }
            std::cout << "\n";
        }
    }
    
    return 0;
}