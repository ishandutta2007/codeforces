#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n), cnt(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        ++cnt[--a[i]];
    }
    int x = std::max_element(cnt.begin(), cnt.end()) - cnt.begin();
    int ans = 0;
    for (int i = 0; i < 100; ++i) {
        if (i == x) continue;
        std::vector<int> lst(2 * n + 1, n);
        int cur = n;
        lst[n] = 0;
        for (int j = 0; j < n; ++j) {
            cur += (a[j] == x) ? -1 : (a[j] == i) ? 1 : 0;
            ans = std::max(ans, j + 1 - lst[cur]);
            if (lst[cur] == n) lst[cur] = j + 1;
        }
    }
    std::cout << ans << "\n";
    
    return 0;
}