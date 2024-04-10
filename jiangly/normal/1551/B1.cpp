#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    
    std::vector<int> cnt(26);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (cnt[c] < 2) {
            cnt[c]++;
            ans++;
        }
    }
    
    ans /= 2;
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