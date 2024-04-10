#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    int ans = 0;
    int i = 0;
    while (i < n - 1) {
        if (s[i] == '(') {
            i += 2;
            ans++;
        } else {
            int j = i + 1;
            while (j < n && s[j] == '(') {
                j++;
            }
            if (j == n) {
                break;
            }
            i = j + 1;
            ans++;
        }
    }
    
    std::cout << ans << " " << n - i << "\n";
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