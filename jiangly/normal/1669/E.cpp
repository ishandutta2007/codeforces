#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int cnt[2][11] = {}, cnt2[11][11] = {};
    
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        
        ans += cnt[0][s[0] - 'a'] + cnt[1][s[1] - 'a'] - 2 * cnt2[s[0] - 'a'][s[1] - 'a'];
        
        cnt[0][s[0] - 'a']++;
        cnt[1][s[1] - 'a']++;
        cnt2[s[0] - 'a'][s[1] - 'a']++;
    }
    
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