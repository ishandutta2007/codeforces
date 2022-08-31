#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, h, m, k;
    std::cin >> n >> h >> m >> k;
    m /= 2;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
        std::cin >> h >> v[i];
    std::vector<std::pair<int, int>> op{std::make_pair(0, 0)};
    auto add = [&](int x, int y) {
        if (x != m)
            op.emplace_back(x, y);
    };
    for (int i = 0; i < n; ++i) {
        v[i] %= m;
        int l = v[i] + 1;
        int r = v[i] + k;
        if (r <= m) {
            add(l, 1);
            add(r, -1);
        } else {
            add(l, 1);
            add(0, 1);
            add(r - m, -1);
        }
    }
    std::sort(op.begin(), op.end());
    int ans = n + 1, t = -1;
    int res = 0;
    for (int i = 0; i < int(op.size()); ) {
        int j = i;
        while (j < int(op.size()) && op[i].first == op[j].first) {
            res += op[j].second;
            ++j;
        }
        if (res < ans) {
            ans = res;
            t = op[i].first;
        }
        i = j;
    }
    std::cout << ans << " " << t << "\n";
    for (int i = 0; i < n; ++i) {
        int l = v[i] + 1;
        int r = v[i] + k;
        if (r <= m) {
            if (l <= t && t < r)
                std::cout << i + 1 << " ";
        } else {
            if (l <= t || t < r - m)
                std::cout << i + 1 << " "; 
        }
    }
    return 0;
}