#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int cnt = 0;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        cnt += std::count(s[i].begin(), s[i].end(), '1');
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int j = 0; j < n; j++) {
            res += (s[j][(i + j) % n] == '1');
        }
        ans = std::max(ans, res);
    }
    
    ans = n - ans + cnt - ans;
    std::cout << ans << "\n";
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