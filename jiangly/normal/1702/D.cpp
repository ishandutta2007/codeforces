#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    int p;
    std::cin >> p;
    
    int sum = 0;
    for (auto c : s) {
        sum += c - 'a' + 1;
    }
    
    int n = s.length();
    std::vector<bool> del(n);
    for (int c = 25; c >= 0; c--) {
        for (int i = 0; i < n; i++) {
            if (sum > p && s[i] == 'a' + c) {
                del[i] = true;
                sum -= c + 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!del[i]) {
            std::cout << s[i];
        }
    }
    
    std::cout << "\n";
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