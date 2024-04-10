#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int w, l;
    std::cin >> w >> l;
    
    std::vector<int> a{1, 2};
    
    auto add = [&](int n) {
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                a.push_back(i);
                a.push_back(n / i);
            }
        }
    };
    
    add(std::gcd(w - 1, l - 1));
    add(std::gcd(w, l - 2));
    add(std::gcd(w - 2, l));
    
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    std::cout << a.size();
    for (auto x : a) {
        std::cout << " " << x;
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