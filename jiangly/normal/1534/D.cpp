#include <bits/stdc++.h>
using i64 = long long;
int n;
std::vector<int> query(int x) {
    std::cout << "? " << x + 1 << std::endl;
    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }
    return d;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    std::vector<std::pair<int, int>> ans;
    auto solve = [&](auto self, int u, auto v, auto d) {
        if (v.size() == 1) {
            return;
        }
        int y = -1;
        for (auto x : v) {
            if (d[x] == 2) {
                y = x;
                break;
            }
        }
        if (y == -1) {
            for (auto x : v) {
                if (x == u) {
                    continue;
                }
                ans.emplace_back(u, x);
            }
            return;
        }
        auto dy = query(y);
        int mid = -1;
        std::vector<int> dmid, vmid, vu, vy;
        for (auto x : v) {
            if (dy[x] > d[x]) {
                vu.push_back(x);
            } else if (dy[x] < d[x]) {
                vy.push_back(x);
            } else {
                vmid.push_back(x);
                if (d[x] == 1) {
                    mid = x;
                }
            }
        }
        ans.emplace_back(u, mid);
        ans.emplace_back(y, mid);
        self(self, u, vu, d);
        self(self, y, vy, dy);
        for (auto &x : d) {
            x--;
        }
        self(self, mid, vmid, d);
    };
    std::vector<int> v(n);
    std::iota(v.begin(), v.end(), 0);
    solve(solve, 0, v, query(0));
    std::cout << "!" << std::endl;
    for (auto [u, v] : ans) {
        std::cout << u + 1 << " " << v + 1 << std::endl;
    }
    return 0;
}