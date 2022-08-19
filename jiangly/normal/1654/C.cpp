#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::multiset<i64> r(a.begin(), a.end());
    
    auto s = std::accumulate(a.begin(), a.end(), 0LL);
    
    int cnt = 1;
    auto f = [&](auto self, auto s) -> void {
        if (cnt > n) {
            return;
        }
        if (r.find(s) != r.end()) {
            r.erase(r.find(s));
            return;
        }
        cnt++;
        self(self, s / 2);
        self(self, s - s / 2);
    };
    f(f, s);
    
    if (cnt == n && r.empty()) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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