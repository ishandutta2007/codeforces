#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    if (n == 1) {
        std::cout << 0 << "\n";
        return 0;
    }
    std::vector<std::vector<int>> p(n + m), q(n + m);
    for (int i = 1; i <= m; ++i) {
        int j;
        std::cin >> j, --j;
        p[j - i + m].push_back(i);
        q[i + j].push_back(i);
    }
    std::vector<std::map<int, int>> l(m + 1), r(m + 1);
    std::function<int(int, int)> fl = [&](int x, int y) {
        if (l[x].count(y)) return l[x][y];
        auto it = upper_bound(q[x + y].begin(), q[x + y].end(), x);
        if (it == q[x + y].end()) return l[x][y] = std::max(0, y - (m + 1 - x));
        return l[x][y] = fl(*it, x + y - *it + 1);
    };
    std::function<int(int, int)> fr = [&](int x, int y) {
        if (r[x].count(y)) return r[x][y];
        auto it = upper_bound(p[y - x + m].begin(), p[y - x + m].end(), x);
        if (it == p[y - x + m].end())
            return r[x][y] = std::min(n - 1, y + (m + 1 - x));
        return r[x][y] = fr(*it, y - x + *it - 1);
    };
    int64 ans = 0;
    for (int i = 0; i < n; ++i) ans += fr(0, i) - fl(0, i) + 1;
    std::cout << ans << "\n";
    return 0;
}