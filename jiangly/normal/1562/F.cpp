#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2E5;

bool isprime[N + 1];

i64 query(int x, int y) {
    std::cout << "? " << x + 1 << " " << y + 1 << std::endl;
    i64 res;
    std::cin >> res;
    return res;
}

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    std::cin >> n;
    
    i64 a[n];
    std::memset(a, 0, sizeof(a));
    if (1LL * n * (n - 1) / 2 <= n + 5000) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                i64 x = query(i, j);
                a[i] = std::gcd(a[i], x);
                a[j] = std::gcd(a[j], x);
            }
        }
        if (n == 3 && a[0] % 2 == 0 && a[1] % 2 == 0 && a[2] % 2 == 0) {
            *std::max_element(a, a + 3) /= 2;
        }
    } else {
        int ids[n];
        std::iota(ids, ids + n, 0);
        std::shuffle(ids, ids + n, rnd);
        
        int u = -1;
        
        for (int i = 0; i < std::min(200, n); i++) {
            int x = ids[i];
            for (int j = 0; j < 25; j++) {
                int y;
                do {
                    y = rnd() % n;
                } while (y == x);
                a[x] = std::gcd(a[x], query(x, y));
            }
            if (isprime[a[x]]) {
                if (u == -1 || a[x] > a[u]) {
                    u = x;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (i != u) {
                a[i] = query(i, u) / a[u];
            }
        }
    }
    std::cout << "!";
    for (int i = 0; i < n; i++) {
        std::cout << " " << a[i];
    }
    std::cout << std::endl;
}

int main() {
    std::fill(isprime + 2, isprime + N + 1, true);
    for (int i = 2; i * i <= N; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isprime[j] = false;
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