#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> a(n - 1), e(n);
        std::vector<int> cnt(n);
        std::vector<bool> vis(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            int k;
            std::cin >> k;
            a[i].resize(k);
            for (int j = 0; j < k; ++j) {
                std::cin >> a[i][j];
                --a[i][j];
                ++cnt[a[i][j]];
                e[a[i][j]].push_back(i);
            }
        }
        std::vector<int> p(n);
        auto work = [&](int s, int v, auto cnt, auto vis) {
            p[0] = v;
            cnt[v] = 0;
            for (int i = s; i >= 1; --i) {
                int x = -1;
                for (int j = 0; j < n; ++j) {
                    if (cnt[j] == 1) x = j;
                }
                if (x == -1) return false;
                p[i] = x;
                int y = -1;
                for (auto j : e[x]) {
                    if (!vis[j]) y = j;
                }
                vis[y] = true;
                for (auto j : a[y]) --cnt[j];
            }
            return true;
        };
        for (int i = n - 1; i >= 1; --i) {
            std::vector<int> can;
            for (int j = 0; j < n; ++j)
                if (cnt[j] == 1) can.push_back(j);
            if (int(can.size()) == 2) {
                if (e[can[0]].size() < e[can[1]].size()) {
                    work(i, can[0], cnt, vis);
                } else if (e[can[0]].size() > e[can[1]].size()) {
                    work(i, can[1], cnt, vis);
                } else {
                    work(i, can[0], cnt, vis) || work(i, can[1], cnt, vis);
                }
                break;
            } else {
                p[i] = can[0];
                int x = -1;
                for (auto j : e[can[0]]) {
                    if (!vis[j]) x = j;
                }
                vis[x] = true;
                for (auto j : a[x]) --cnt[j];
            }
        }
        for (int i = 0; i < n; ++i) std::cout << p[i] + 1 << " \n"[i == n - 1];
    }
    return 0;
}