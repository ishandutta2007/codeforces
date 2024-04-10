#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::string s;
    std::cin >> s;
    
    int cnt[26] = {};
    for (auto c : s) {
        cnt[c - 'a']++;
    }
    
    int odd = 0;
    for (int i = 0; i < 26; i++) {
        odd += cnt[i] % 2;
    }
    
    int v = (n - std::max(0, odd - k)) / k;
    std::cout << std::max((n - odd) / k, v - (v + 1) % 2) << "\n";
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