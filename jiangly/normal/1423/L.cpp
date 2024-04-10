#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
constexpr int N = 1000;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, s, d;
    std::cin >> n >> s >> d;
    std::vector<std::bitset<N>> a(s), base;
    std::vector<int> b(s), fst;
    for (int i = 0; i < s; ++i) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            std::cin >> x;
            a[i][--x] = 1;
        }
    }
    for (int i = 0; i < s; ++i) {
        int x = a[i]._Find_first();
        for (int j = i + 1; j < s; ++j) {
            int y = a[j]._Find_first();
            if (y < x) std::swap(a[i], a[j]), std::swap(b[i], b[j]), x = y;
        }
        if (x == N) break;
        base.push_back(a[i]);
        fst.push_back(x);
        b[i] ^= 1 << i;
        for (int j = i + 1; j < s; ++j) {
            if (a[j][x]) {
                a[j] ^= a[i];
                b[j] ^= 1 << i;
            }
        }
    }
    int rk = base.size();
    int m = s / 2;
    std::vector<std::pair<int, int>> f, g;
    std::function<void(int, int, int, int)> dfs = [&](int cur, int goal, int x, int cnt) {
        if (cur == goal) {
            f.emplace_back(x, cnt);
            return;
        }
        dfs(cur + 1, goal, x, cnt);
        dfs(cur + 1, goal, x ^ b[cur], cnt + 1);
    };
    dfs(0, m, 0, 0);
    std::swap(f, g);
    dfs(m, s, 0, 0);
    std::sort(f.begin(), f.end());
    std::sort(g.begin(), g.end());
    while (d--) {
        std::bitset<N> a;
        int k;
        std::cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            std::cin >> x;
            a[--x] = 1;
        }
        int x = 0;
        for (int i = 0; i < rk; ++i) {
            if (a[fst[i]]) {
                a ^= base[i];
                x ^= 1 << i;
            }
        }
        if (a != 0) {
            std::cout << -1 << "\n";
            continue;
        }
        int ans = s;
        for (auto [y, c] : f) {
            auto it = std::lower_bound(g.begin(), g.end(), std::make_pair(x ^ y, 0));
            if (it != g.end() && it->first == (x ^ y)) ans = std::min(ans, c + it->second);
        }
        std::cout << ans << "\n";
    }
    return 0;
}