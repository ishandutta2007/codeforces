#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::map<int, int> s;
    
    auto add = [&](int i, int x) {
        s[i] = x;
        
        auto it = s.find(i);
        
        if (it != s.begin() && x >= std::prev(it)->second) {
            s.erase(it);
            return;
        }
        
        while (std::next(it) != s.end() && x <= std::next(it)->second) {
            s.erase(std::next(it));
        }
    };
    
    for (int i = 0; i < n; i++) {
        add(i, a[i]);
    }
    
    for (int i = 0; i < m; i++) {
        int k, d;
        std::cin >> k >> d;
        k--;
        a[k] -= d;
        add(k, a[k]);
        
        std::cout << s.size() << " \n"[i == m - 1];
    }
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