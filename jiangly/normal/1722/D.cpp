#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    i64 ans = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            ans += i;
            a[i] += n - 1 - i - i;
        } else {
            ans += n - 1 - i;
            a[i] += i - (n - 1 - i);
        }
    }
    
    std::sort(a.begin(), a.end(), std::greater());
    for (int i = 0; i < n; i++) {
        ans += std::max(0, a[i]);
        std::cout << ans << " \n"[i == n - 1];
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