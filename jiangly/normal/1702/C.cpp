#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::map<int, int> left, right;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (!left.contains(x)) {
            left[x] = i;
        }
        right[x] = i;
    }
    
    for (int i = 0; i < k; i++) {
        int a, b;
        std::cin >> a >> b;
        
        if (left.contains(a) && left.contains(b) && left[a] <= right[b]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
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