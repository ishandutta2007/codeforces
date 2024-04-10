#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    
    int x = 0;
    int pos[n];
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            pos[i] = x++;
        }
    }
    
    if (x == 1 || x == 2) {
        std::cout << "NO\n";
        return;
    }
    
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                std::cout << "X";
            } else if (s[i] == '2' && s[j] == '2' && (pos[i] + 1) % x == pos[j]) {
                std::cout << "+";
            } else if (s[i] == '2' && s[j] == '2' && (pos[j] + 1) % x == pos[i]) {
                std::cout << "-";
            } else {
                std::cout << "=";
            }
        }
        std::cout << "\n";
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