#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int s;
    std::cin >> s;
    
    std::string t;
    for (int i = 9; i && s; i--) {
        const int x = std::min(i, s);
        s -= x;
        t += '0' + x;
    }
    std::reverse(t.begin(), t.end());
    
    std::cout << t << "\n";
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