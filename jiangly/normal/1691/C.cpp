#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::string s;
    std::cin >> s;
    
    int cnt = std::count(s.begin(), s.end(), '1');
    
    if (cnt == 0) {
        std::cout << "0\n";
        return;
    }
    
    int first = 0, last = n - 1;
    while (s[first] == '0') {
        first++;
    }
    while (s[last] == '0') {
        last--;
    }
    
    int ans = 11 * cnt;
    if (k >= first + n - 1 - last && first != last) {
        ans -= 11;
    } else if (k >= n - 1 - last) {
        ans -= 10;
    } else if (k >= first) {
        ans -= 1;
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