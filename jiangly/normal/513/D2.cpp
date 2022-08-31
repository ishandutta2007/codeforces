#include <bits/stdc++.h>
using i64 = long long;
void gg() {
    std::cout << "IMPOSSIBLE\n";
    std::exit(0);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, c;
    std::cin >> n >> c;
    std::vector<std::vector<std::pair<int, int>>> e(n);
    std::vector<int> ans;
    ans.reserve(n);
    std::vector<int> d(n);
    for (int i = 0; i < c; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        if (a >= b) {
            gg();
        }
        std::string type;
        std::cin >> type;
        d[a]++;
        d[b]--;
        e[a].emplace_back(b, type == "LEFT");
    }
    for (int i = 1; i < n; i++) {
        d[i] += d[i - 1];
    }
    std::vector<int> nxt(n);
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = d[i] == 0 ? i : nxt[i + 1];
    }
    std::function<int(int, int)> solve = [&](int l, int r) {
        if (l > r) {
            return l - 1;
        }
        int lmx = l;
        int rmn = n;
        int rmx = l;
        for (int i = 0; i < int(e[l].size()); i++) {
            if (e[l][i].second == 1) {
                lmx = std::max(lmx, e[l][i].first);
            } else {
                rmn = std::min(rmn, e[l][i].first);
                rmx = std::max(rmx, e[l][i].first);
            }
        }
        if (lmx >= rmn) {
            gg();
        }
        r = std::max(r, rmx);
        int mid = solve(l + 1, lmx);
        if (mid >= rmn) {
            gg();
        }
        ans.push_back(l);
        return solve(mid + 1, r);
    };
    solve(0, n - 1);
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] + 1 << " \n"[i == n - 1];
    }
    return 0;
}