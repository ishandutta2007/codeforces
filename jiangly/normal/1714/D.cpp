#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string t;
    std::cin >> t;
    
    int n;
    std::cin >> n;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    int cur = 0;
    std::vector<std::array<int, 2>> ans;
    while (cur < int(t.length())) {
        std::array v{cur, -1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= cur && j + s[i].length() <= t.length(); j++) {
                if (t.substr(j, s[i].length()) == s[i]) {
                    v = std::max(v, std::array{j + int(s[i].length()), i, j});
                }
            }
        }
        if (v[0] == cur) {
            std::cout << "-1\n";
            return;
        }
        cur = v[0];
        ans.push_back({v[1], v[2]});
    }
    
    std::cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        std::cout << x + 1 << " " << y + 1 << "\n";
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