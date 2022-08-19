#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    bool nice = true;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        if (a[i] % 2 != i % 2) {
            nice = false;
        }
    }
    
    if (!nice) {
        std::cout << "-1\n";
        return;
    }
    
    std::vector<int> res;
    
    for (int i = n - 2; i >= 1; i -= 2) {
        int x = 0;
        while (a[x] != i) {
            x++;
        }
        int y = 0;
        while (a[y] != i + 1) {
            y++;
        }
    
        auto rev = [&](int p) {
            assert(p % 2 == 1);
            std::reverse(a, a + p);
            res.push_back(p);
            if (x < p) {
                x = p - 1 - x;
            }
            if (y < p) {
                y = p - 1 - y;
            }
        };
        
        rev(y + 1);
        
        rev(x);
        
        rev(x + 2);
        
        rev(3);
        
        rev(i + 2);
    }
    
    std::cout << res.size() << "\n";
    for (int i = 0; i < int(res.size()); i++) {
        std::cout << res[i];
        if (i + 1 != int(res.size())) {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}