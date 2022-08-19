#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int d, n, m;
    std::cin >> n >> d >> m;
    int64_t ans = 0;
    std::vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x <= m) {
            a.push_back(x);
        } else {
            b.push_back(x);
        }
    }
    std::sort(a.begin(), a.end(), std::greater<>());
    std::sort(b.begin(), b.end(), std::greater<>());
    std::vector<int64_t> sa(a.size() + 1), sb(b.size() + 1);
    for (int i = 0; i < int(a.size()); ++i)
        sa[i + 1] = sa[i] + a[i];
    for (int i = 0; i < int(b.size()); ++i)
        sb[i + 1] = sb[i] + b[i];
    for (int x = 0; x <= int(a.size()); ++x) {
        int y = (n - x + d) / (d + 1);
        ans = std::max(ans, sa[x] + (y <= int(b.size()) ? sb[y] : sb.back()));
    }
    std::cout << ans << "\n";
    return 0;
}