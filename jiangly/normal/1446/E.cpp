#include <bits/stdc++.h>

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    int a[510][510] {};
    int deg[510][510] {};
    std::queue<std::pair<int, int>> que;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        x += 5, y += 5;
        que.emplace(x, y);
        a[x][y] = 1;
    }
    
    int cnt = 0;
    int ans = -n;
    std::vector<std::pair<int, int>> v;
    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();
        if (a[x][y] == 2 && deg[x][y] == 3) {
            v.emplace_back(x, y);
        }
        ++cnt;
        for (auto [x1, y1] : {std::make_pair(x + 1, y), {x - 1, y}, {x % 2 == 1 ? x + 1 : x - 1, x % 2 == 1 ? y - 1 : y + 1}}) {
            if (++deg[x1][y1] >= 2 && !a[x1][y1]) {
                a[x1][y1] = 2;
                que.emplace(x1, y1);
            }
        }
    }
    
    DSU t(510 * 510);
    
    for (int x = 0; x < 510; ++x) {
        for (int y = 0; y < 510; ++y) {
            if (a[x][y]) {
                for (auto [x1, y1] : {std::make_pair(x + 1, y), {x - 1, y}, {x % 2 == 1 ? x + 1 : x - 1, x % 2 == 1 ? y - 1 : y + 1}}) {
                    if (x1 < x) continue;
                    if (a[x1][y1] && !t.merge(x1 * 510 + y1, x * 510 + y)) {
                        std::cout << "SICK\n";
                        return 0;
                    } 
                }
            }
        }
    }
    for (auto [x, y] : v) {
        for (auto [x1, y1] : {std::make_pair(x + 1, y), {x - 1, y}, {x % 2 == 1 ? x + 1 : x - 1, x % 2 == 1 ? y - 1 : y + 1}}) {
            if (deg[x1][y1] >= 2) {
                ans += 2;
                break;
            }
        }
    }
    
    ans += 2 * cnt;
    std::cout << "RECOVERED\n";
    std::cout << ans << "\n";
    
    return 0;
}