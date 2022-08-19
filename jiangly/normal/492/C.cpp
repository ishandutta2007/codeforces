#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, r, avg;
    std::cin >> n >> r >> avg;
    std::vector<std::pair<int, int>> a(n);
    i64 need = i64(avg) * n;
    i64 cur = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].second >> a[i].first;
        cur += a[i].second;
    }
    std::sort(a.begin(), a.end());
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int t = std::min<i64>(std::max<i64>(0, need - cur), r - a[i].second);
        cur += t;
        ans += i64(t) * a[i].first;
    }
    std::cout << ans << "\n";
    return 0;
}