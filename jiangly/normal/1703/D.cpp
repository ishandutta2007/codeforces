#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::set<std::string> s(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 1; j < int(a[i].length()); j++) {
            if (s.contains(a[i].substr(0, j)) && s.contains(a[i].substr(j))) {
                ok = true;
            }
        }
        std::cout << ok;
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