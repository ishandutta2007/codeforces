#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::priority_queue<int> h;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        h.push(x);
    }
    
    for (int i = n; i; i--) {
        while (h.top() > i) {
            int x = h.top();
            h.pop();
            h.push(x / 2);
        }
        if (h.top() != i) {
            std::cout << "NO\n";
            return;
        }
        h.pop();
    }
    
    std::cout << "YES\n";
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