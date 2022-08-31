#include <bits/stdc++.h>

constexpr int P = 998244353;

int power(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = 1ll * a * a % P)
        if (b & 1)
            res = 1ll * res * a % P;
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> d(n);
    for (int i = 0; i < n; ++i)
        std::cin >> d[i];
    std::sort(d.begin(), d.end());
    
    std::vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i)
        pre[i + 1] = (pre[i] + d[i]) % P;
    
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        
        int k = std::lower_bound(d.begin(), d.end(), b) - d.begin();
        int g = std::max(0, n - k - a);
        int l = std::max(0, n - k - a + 1);
        
        int ans = (1ll * g * power(n - k, P - 2) % P * (pre[n] - pre[k] + P) + 1ll * l * power(n - k + 1, P - 2) % P * pre[k]) % P;
        
        std::cout << ans << "\n";
    }
    
    return 0;
}