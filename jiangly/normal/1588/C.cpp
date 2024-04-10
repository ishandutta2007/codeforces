#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    i64 res = 0;
    
    std::vector<i64> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + (i % 2 == 0 ? a[i] : -a[i]);
    }
    
    std::set<int> g;
    for (int i = 0; i <= n; i += 2) {
        g.insert(i);
    }
    
    std::vector<int> p(n + 1);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) { return s[i] < s[j] || (s[i] == s[j] && i < j); });
    
    for (int l = 0, r; l <= n; l = r) {
        r = l;
        while (r <= n && s[p[l]] == s[p[r]]) {
            if (p[r] % 2 == 0) {
                g.erase(p[r]);
            }
            r++;
        }
        
        auto it = g.end();
        for (int i = l, j = 0; i < r; i++) {
            auto jt = g.lower_bound(p[i]);
            if (it != jt) {
                j = 0;
            }
            it = jt;
            res += j;
            j++;
        }
        for (int i = l; i < r; i++) {
            if (p[i] % 2 == 1) {
                g.insert(p[i]);
            }
        }
    }
    
    std::cout << res << "\n";
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