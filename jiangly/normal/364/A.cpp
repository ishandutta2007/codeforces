#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a;
    std::cin >> a;
    
    std::string s;
    std::cin >> s;
    int n = s.length();
    
    std::vector<int> cnt(9 * n + 1);
    for (int l = 0; l < n; l++) {
        int x = 0;
        for (int r = l; r < n; r++) {
            x += s[r] - '0';
            cnt[x]++;
        }
    }
    
    if (a == 0) {
        i64 ans = i64(cnt[0]) * cnt[0];
        for (int i = 1; i <= 9 * n; i++) {
            ans += 2LL * cnt[0] * cnt[i];
        }
        std::cout << ans << "\n";
        return 0;
    }
    
    i64 ans = 0;
    for (int i = 1; i <= 9 * n; i++) {
        if (a % i == 0 && a / i <= 9 * n) {
            ans += i64(cnt[i]) * cnt[a / i];
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}