#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<i64> p(n);
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] + std::max(0, a[i - 1] - a[i]);
    }
    
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        if (x < y) {
            std::cout << p[y] - p[x] << "\n";
        } else {
            std::cout << a[x] - a[y] + p[x] - p[y] << "\n";
        }
    }
    
    return 0;
}