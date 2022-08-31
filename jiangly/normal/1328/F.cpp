#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());
    long long ans = std::numeric_limits<long long>::max();
    std::vector<long long> pre(n + 1);
    for (int i = 0; i < n; ++i)
        pre[i + 1] = pre[i] + a[i];
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && a[i] == a[j])
            ++j;
        if (j - i >= k) {
            std::cout << 0 << "\n";
            return 0;
        }
        i = j;
    }
    for (int i = 0; i < n; ++i) {
        if (i + 1 >= k)
            ans = std::min(ans, 1ll * a[i] * (i + 1) - pre[i + 1] - (i + 1 - k));
        if (n - i >= k)
            ans = std::min(ans, pre[n] - pre[i] - 1ll * a[i] * (n - i) - (n - i - k));
        ans = std::min(ans, pre[n] - pre[i] - 1ll * a[i] * (n - i) + 1ll * a[i] * i - pre[i] - (n - k));
    }
    std::cout << ans << "\n";
    return 0;
}