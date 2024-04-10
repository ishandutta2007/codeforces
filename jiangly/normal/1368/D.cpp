#include <bits/stdc++.h>
constexpr int N = 2e5;
int n;
int a[N];
int cnt[20];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        for (int j = 0; j < 20; ++j)
            cnt[j] += a[i] >> j & 1;
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int b = 0;
        for (int j = 0; j < 20; ++j)
            b |= (i < cnt[j]) << j;
        ans += 1ll * b * b;
    }
    std::cout << ans << "\n";
    return 0;
}