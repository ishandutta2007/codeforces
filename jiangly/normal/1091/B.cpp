#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    i64 x = 0, y = 0;
    for (int i = 0; i < 2 * n; i++) {
        int a, b;
        std::cin >> a >> b;
        x += a;
        y += b;
    }
    
    x /= n;
    y /= n;
    
    std::cout << x << " " << y << "\n";
    
    return 0;
}