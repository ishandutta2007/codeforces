#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        i64 ans = 0;
        std::map<int, i64> sum;
        for (int i = 0; i < n; i++) {
            ans += sum[a[i]] * (n - i);
            sum[a[i]] += i + 1;
        }
        std::cout << ans << "\n";
    }
    return 0;
}