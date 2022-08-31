#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    int n = s.length();
    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    
    if (first == -1) {
        std::cout << "0\n";
    } else {
        bool res = true;
        for (int i = first; i <= last; i++) {
            if (s[i] == '1') {
                res = false;
            }
        }
        std::cout << (res ? 1 : 2) << "\n";
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