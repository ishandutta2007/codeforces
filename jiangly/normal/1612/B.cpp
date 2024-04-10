#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    
    if (n - a - (b > a) < n / 2 - 1 || b - 1 - (a < b) < n / 2 - 1) {
        std::cout << "-1\n";
        return;
    }
    
    std::vector<int> p;
    for (int i = n; int(p.size()) < n / 2 - 1; i--) {
        if (i != b) {
            p.push_back(i);
        }
    }
    p.push_back(a);
    for (int i = 1; int(p.size()) < n - 1; i++) {
        if (i != a) {
            p.push_back(i);
        }
    }
    p.push_back(b);
    
    for (int i = 0; i < n; i++) {
        std::cout << p[i] << " \n"[i == n - 1];
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