#include <bits/stdc++.h>

constexpr int N = 1e6;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    bool isprime[N + 1];
    std::fill(isprime + 2, isprime + N + 1, true);
    for (int i = 2; i * i <= N; ++i)
        if (isprime[i])
            for (int j = i * i; j <= N; j += i) isprime[j] = false;
    int a[N + 1] = {};
    a[1] = 1;
    for (int i = 1; i <= N; ++i) {
        if (isprime[i]) {
            ++a[i];
            if (1ll * i * i <= N) --a[i * i];
        }
    }
    for (int i = 1; i <= N; ++i) a[i] += a[i - 1];
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << a[n] << "\n";
    }
    
    return 0;
}