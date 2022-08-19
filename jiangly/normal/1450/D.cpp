#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), pos(n), cnt(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            --a[i];
            pos[a[i]] = i;
            ++cnt[a[i]];
        }
        std::string ans(n, '0');
        if (cnt == std::vector<int>(n, 1)) {
            ans[0] = '1';
        }
        int l = 0, r = n;
        int k = 0;
        while (k < n - 1 && cnt[k] == 1 && (pos[k] == l || pos[k] == r - 1)) {
            if (pos[k] == l) {
                ++l;
            } else {
                --r;
            }
            ++k;
        }
        std::fill(ans.end() - k, ans.end(), '1');
        if (cnt[k] > 0) {
            ans[n - k - 1] = '1';
        }
        std::cout << ans << "\n";
    }
    
    return 0;
}