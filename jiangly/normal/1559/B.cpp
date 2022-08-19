#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    for (int i = 1; i < n; i++) {
        if (s[i] == '?' && s[i - 1] != '?') {
            s[i] = (s[i - 1] == 'B' ? 'R' : 'B');
        }
    }
    
    if (s[n - 1] == '?') {
        s[n - 1] = 'R';
    }
    
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '?') {
            s[i] = (s[i + 1] == 'B' ? 'R' : 'B');
        }
    }
    
    std::cout << s << "\n";
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