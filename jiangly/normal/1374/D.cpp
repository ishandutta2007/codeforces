#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::map<int, long long> s;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            a = (k - a % k) % k;
            if (!a)
                continue;
            if (s.count(a)) {
                s[a] += k;
            } else {
                s[a] = a;
            }
            ans = std::max(ans, s[a] + 1);
        }
        std::cout << ans << "\n";
    }
    return 0;
}