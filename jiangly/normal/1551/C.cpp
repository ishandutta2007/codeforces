#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    int ans = 0;
    for (int c = 0; c < 5; c++) {
        std::vector<int> f(n);
        for (int i = 0; i < n; i++) {
            for (auto x : s[i]) {
                if (x == 'a' + c) {
                    f[i]++;
                } else {
                    f[i]--;
                }
            }
        }
        
        std::sort(f.begin(), f.end(), std::greater());
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += f[i];
            if (sum <= 0) {
                break;
            }
            ans = std::max(ans, i + 1);
        }
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