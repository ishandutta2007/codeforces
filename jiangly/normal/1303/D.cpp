#include <iostream>
#include <algorithm>
int t, m;
long long n;
int cnt[64];
void solve() {
    std::cin >> n >> m;
    std::fill(cnt, cnt + 64, 0);
    long long sum = 0;
    for (int i = 0; i < m; ++i) {
        int a;
        std::cin >> a;
        ++cnt[std::__lg(a)];
        sum += a;
    }
    if (sum < n) {
        std::cout << -1 << "\n";
        return;
    }
    int ans = 0;
    for (int i = 0; i < 60; ++i) {
        if (n >> i & 1) {
            int j = i;
            while (cnt[j] == 0)
                ++j;
            --cnt[j];
            while (j > i) {
                --j;
                ++cnt[j];
                ++ans;
            }
        }
        cnt[i + 1] += cnt[i] / 2;
    }
    std::cout << ans << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}