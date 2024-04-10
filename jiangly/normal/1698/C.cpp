#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b;
    std::map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (++cnt[a[i]] <= 3) {
            b.push_back(a[i]);
        }
    }
    
    n = b.size();
    a = b;
    
    if (cnt.size() >= 5) {
        std::cout << "NO\n";
        return;
    }
    
    std::set<i64> s(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (!s.contains(1LL * a[i] + a[j] + a[k])) {
                    std::cout << "NO\n";
                    return;
                }
            }
        }
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