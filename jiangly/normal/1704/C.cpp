#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    std::sort(a.begin(), a.end());
    
    std::vector<int> b;
    for (int i = 0; i < m - 1; i++) {
        b.push_back(a[i + 1] - a[i] - 1);
    }
    b.push_back(a[0] + n - a[m - 1] - 1);
    
    std::sort(b.begin(), b.end(), std::greater());
    
    int ans = 0, cur = 0;
    for (auto x : b) {
        if (x - 2 * cur <= 0) {
            break;
        }
        if (x - 2 * cur <= 2) {
            cur++;
            ans++;
        } else {
            ans += x - 2 * cur - 1;
            cur += 2;
        }
    }
    
    std::cout << n - ans << "\n";
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