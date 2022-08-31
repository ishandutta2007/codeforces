#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    std::vector<int> cnt(26);
    for (auto c : s) {
        cnt[c - 'a']++;
    }
    
    int i = 0;
    while (cnt[s[i] - 'a'] > 1) {
        cnt[s[i] - 'a']--;
        i++;
    }
    
    std::cout << s.substr(i) << "\n";
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