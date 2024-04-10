#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    
    int i = 0;
    while (i < n && a[i] == a[n - i - 1]) {
        i++;
    }
    
    if (i == n) {
        std::cout << "YES\n";
        return;
    }
    
    for (auto x : {a[i], a[n - i - 1]}) {
        auto b = a;
        b.erase(std::remove(b.begin(), b.end(), x), b.end());
        auto c = b;
        std::reverse(c.begin(), c.end());
        if (b == c) {
            std::cout << "YES\n";
            return;
        }
    }
    
    std::cout << "NO\n";
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