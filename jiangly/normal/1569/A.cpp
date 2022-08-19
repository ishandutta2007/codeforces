#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            std::cout << i + 1 << " " << i + 2 << "\n";
            return;
        }
    }
    
    std::cout << "-1 -1\n";
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