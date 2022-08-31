#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> deg(n);
    for (int i = 1; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        deg[x]++;
    }
    
    std::vector<int> a { 1 };
    for (int i = 0; i < n; i++) {
        if (deg[i] > 0) {
            a.push_back(deg[i]);
        }
    }
    std::sort(a.begin(), a.end(), std::greater());
    
    int l = a.size(), r = n;
    while (l < r) {
        int x = (l + r) / 2;
        
        int cnt = 0;
        for (int i = 0; i < int(a.size()); i++) {
            cnt += std::max(0, a[i] - x + i);
        }
        if (int(a.size()) + cnt <= x) {
            r = x;
        } else {
            l = x + 1;
        }
    }
    
    std::cout << l << "\n";
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