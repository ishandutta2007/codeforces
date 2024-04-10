#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    
    std::vector<int64_t> suf(n + 1);
    for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i];
    
    int64_t ans = 0;
    int x = std::partition_point(suf.begin() + 1, suf.end(), [&](int64_t x) { return x < 0; }) - suf.begin();
    for (int i = x; i <= n; ++i) ans += suf[i];
    for (int i = k + 1; i < x; i += k + 1) ans += suf[i];
    
    std::cout << ans << "\n";
    
    return 0;
}