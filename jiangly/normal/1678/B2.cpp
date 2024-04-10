#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    int ans = 0, seg = 0;
    int last = -1;
    
    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[i + 1]) {
            ans++;
        } else {
            if (last != -1 && last != s[i] - '0') {
                seg++;
            }
            last = s[i] - '0';
        }
    }
    
    seg++;
    
    std::cout << ans << " " << seg << "\n";
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