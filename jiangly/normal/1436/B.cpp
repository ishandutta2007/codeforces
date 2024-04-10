#include <bits/stdc++.h>
constexpr int N = 1e5;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    bool isprime[N];
    std::fill(isprime + 2, isprime + N, true);
    for (int i = 2; i * i < N; ++i)
        if (isprime[i])
            for (int j = i * i; j < N; j += i) isprime[j] = false;
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int a = 1;
        while (isprime[a] || !isprime[a + n - 1]) ++a;
        int b = 1;
        while (isprime[b] || !isprime[a * (n - 1) + b]) ++b;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) std::cout << (i == n && j == n ? b : i < n && j < n ? 1 : a) << " \n"[j == n];
    }
    
    return 0;
}