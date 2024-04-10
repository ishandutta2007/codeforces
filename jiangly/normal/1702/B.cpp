#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    int n = s.length();
    
    int cnt = 0, ans = 1;
    std::vector<bool> have(26);
    for (int i = 0; i < n; i++) {
        if (cnt + !have[s[i] - 'a'] > 3) {
            have.assign(26, false);
            cnt = 0;
            ans++;
        }
        cnt += !have[s[i] - 'a'];
        have[s[i] - 'a'] = true;
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