#include <bits/stdc++.h>

using i64 = long long;

int query(int w) {
    std::cout << "? " << w << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    int l = 1, r = 2000 * 2000;
    
    while (l < r) {
        int x = (l + r) / 2;
        if (query(x) == 1) {
            r = x;
        } else {
            l = x + 1;
        }
    }
    
    int ans = l;
    
    for (int i = 1; i <= n; i++) {
        int x = query(l / i);
        if (x != 0) {
            ans = std::min(ans, l / i * x);
        }
    }
    
    std::cout << "! " << ans << std::endl;
    
    return 0;
}