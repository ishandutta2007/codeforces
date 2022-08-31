#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> p(n);
    std::vector<std::vector<int>> adj(n);
    p[0] = -1;
    for (int i = 1; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
        adj[p[i]].push_back(i);
        adj[i].push_back(p[i]);
    }
    
    std::vector<int> d(n, -1);
    std::queue<std::array<int, 2>> que;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            que.push({i, 0});
        }
    }
    while (!que.empty()) {
        auto [x, v] = que.front();
        que.pop();
        
        if (d[x] != -1) {
            continue;
        }
        d[x] = v;
        
        for (auto y : adj[x]) {
            que.push({y, v + 1});
        }
    }
    
    std::vector<int> euler(n);
    
    int cur = 0;
    
    const int log = std::__lg(2 * n - 1) + 1;
    std::vector<std::vector<int>> st(2 * n - 1, std::vector<int>(log + 1));
    
    std::vector<int> dep(n);
    std::function<void(int)> dfs = [&](int x) {
        st[cur][0] = x;
        euler[x] = cur++;
        for (auto y : adj[x]) {
            if (y == p[x]) {
                continue;
            }
            dep[y] = dep[x] + 1;
            dfs(y);
            st[cur++][0] = x;
        }
    };
    dfs(0);
    
    for (int j = 0; j < log; j++) {
        for (int i = 0; i + (2 << j) <= 2 * n - 1; i++) {
            st[i][j + 1] = dep[st[i][j]] < dep[st[i + (1 << j)][j]] ? st[i][j] : st[i + (1 << j)][j];
        }
    }
    
    auto lca = [&](int x, int y) {
        x = euler[x];
        y = euler[y];
        if (x > y) {
            std::swap(x, y);
        }
        int k = std::__lg(y - x + 1);
        return st[x][k] < st[y + 1 - (1 << k)][k] ? st[x][k] : st[y + 1 - (1 << k)][k];
    };
    
    auto dist = [&](int x, int y) {
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    };
    
    const int maxd = *std::max_element(d.begin(), d.end());
    
    std::vector<std::array<int, 3>> a(maxd + 1, {-1, -1, -1});
    
    auto merge = [&](auto a, auto b) {
        if (a[0] == -1) {
            return b;
        }
        if (b[0] == -1) {
            return a;
        }
        auto c = std::max(a, b);
        for (auto x : {a[1], a[2]}) {
            for (auto y : {b[1], b[2]}) {
                c = std::max(c, std::array{dist(x, y), x, y});
            }
        }
        return c;
    };
    
    for (int i = 0; i < n; i++) {
        a[d[i]] = merge(a[d[i]], std::array{0, i, i});
    }
    auto suf = a;
    for (int i = maxd - 1; i >= 0; i--) {
        suf[i] = merge(suf[i], suf[i + 1]);
    }
    
    auto check = [&](int ans, int i, int x) {
        int j = std::max(0, ans - i - x);
        if (j > maxd) {
            return false;
        }
        for (auto x : {a[i][1], a[i][2]}) {
            for (auto y : {suf[j][1], suf[j][2]}) {
                if (dist(x, y) >= ans) {
                    return true;
                }
            }
        }
        return false;
    };
    
    int q;
    std::cin >> q;
    
    for (int t = 0; t < q; t++) {
        int x;
        std::cin >> x;
        
        int ans = 0;
        for (int i = 0; i <= maxd; i++) {
            while (check(ans + 1, i, x)) {
                ans++;
            }
        }
        
        std::cout << ans << " \n"[t == q - 1];
    }
    
    return 0;
}