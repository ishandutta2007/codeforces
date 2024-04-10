#include <iostream>
#include <cstdlib>
int cnt[1000];
void solve() {
    int n, s, k;
    std::cin >> n >> s >> k;
    for (int i = 0; i < k; ++i) {
        cnt[i] = 0;
        if (s - i < 1)
            ++cnt[i];
        if (s + i > n)
            ++cnt[i];
    }
    cnt[0] = 1;
    for (int i = 0; i < k; ++i) {
        int x;
        std::cin >> x;
        if (std::abs(x - s) < k)
            ++cnt[std::abs(x - s)];
    }
    int ans = 0;
    while (ans < k && cnt[ans] == 2)
        ++ans;
    std::cout << ans << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}