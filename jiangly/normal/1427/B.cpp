#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        std::vector<int> a;
        int lst = -2;
        int ans = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'W') {
                if (lst != i - 1 && lst >= 0) a.push_back(i - lst - 1);
                ans += (lst == i - 1) + 1;
                lst = i;
                cnt += 1;
            }
        }
        k = std::min(n - cnt, k);
        ans += 2 * k;
        if (lst < 0) {
            if (k > 0) --ans;
        } else {
            std::sort(a.begin(), a.end());
            for (auto x : a) {
                if (k >= x) {
                    ++ans;
                    k -= x;
                }
            }
        }
        std::cout << ans << "\n";
    }
    
    return 0;
}