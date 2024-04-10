#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    int f[n + 1], g[n + 2];
    std::memset(g, 0, sizeof(g));
    f[n] = g[n] = 1;
    for (int i = n - 1; i > 0; i--) {
        f[i] = g[i + 1];
        for (int j = 2; j * i <= n; j++) {
            int v = (g[i * j] - g[std::min(i * j + j, n + 1)] + m) % m;
            f[i] = (f[i] + v) % m;
        }
        g[i] = (f[i] + g[i + 1]) % m;
    }
    
    std::cout << f[1] << "\n";
    
    return 0;
}