#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n);
    for (int i = 0; i < m; i++) {
        int x;
        std::cin >> x;
        x--;
        a[x]++;
    }
    
    int l = 0, r = m;
    while (l < r) {
        int x = (l + r) / 2;
        
        i64 time = 0, work = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= x) {
                time += (x - a[i]) / 2;
            } else {
                work += a[i] - x;
            }
        }
        
        if (time >= work) {
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