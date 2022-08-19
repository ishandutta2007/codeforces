#include <bits/stdc++.h>
 
int lowbit(int x) { return x & -x; }
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int m;
    std::cin >> m;
    
    std::vector<int> x1(m), y1(m), x2(m), y2(m);
    std::vector<std::pair<int, int>> s{{0, 0}};
    
    auto work = [&](int a, int b) {
        while (a > 0 || b > 0) {
            s.emplace_back(a, b);
            if (b == 0 || (a > 0 && lowbit(a) < lowbit(b))) {
                s.emplace_back(a - 1, b);
                a ^= lowbit(a);
            } else {
                s.emplace_back(a, b - 1);
                b ^= lowbit(b);
            }
        }
    };
    
    for (int i = 0; i < m; ++i) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        x1[i] = a, y1[i] = b;
        x2[i] = c, y2[i] = d;
        work(a, b);
        work(c, d);
    }
    
    std::sort(s.begin(), s.end());
    s.erase(std::unique(s.begin(), s.end()), s.end());
    
    auto getId = [&](int x, int y) { return std::lower_bound(s.begin(), s.end(), std::make_pair(x, y)) - s.begin(); };
    
    int n = s.size();
    std::vector<int> gx(n), gy(n);
    for (int i = 0; i < n; ++i) gx[i] = gy[i] = i;
    std::vector<int> parent(n, -1), dep(n), h(n, -1), type(n, -1);
    for (int i = 1; i < n; ++i) {
        auto [x, y] = s[i];
        dep[i] = x + y;
        type[i] = (y == 0 || (x > 0 && lowbit(x) < lowbit(y))) ? 0 : 1;
        while ((x > 0 || y > 0) && (y == 0 || (x > 0 && lowbit(x) < lowbit(y)) ? 0 : 1) == type[i]) {
            if (type[i] == 0) {
                x ^= lowbit(x);
            } else {
                y ^= lowbit(y);
            }
        }
        h[i] = getId(x, y);
        if (type[i] == 0) {
            parent[i] = gx[h[i]];
            gx[h[i]] = i;
        } else {
            parent[i] = gy[h[i]];
            gy[h[i]] = i;
        }
    }
    
    auto lca = [&](int u, int v) {
        while (h[u] != h[v]) {
            if (h[v] == -1 || (h[u] >= 0 && dep[h[u]] > dep[h[v]])) u = h[u];
            else v = h[v];
        }
        if (type[u] == type[v]) {
            return dep[u] < dep[v] ? u : v;
        } else {
            return h[u];
        }
    };
    
    std::vector<int> a(n);
    
    for (int i = 0; i < m; ++i) {
        int u = getId(x1[i], y1[i]);
        int v = getId(x2[i], y2[i]);
        ++a[u], ++a[v];
        int l = lca(u, v);
        --a[l];
        if (l > 0) --a[parent[l]];
    }
    
    for (int i = n - 1; i > 0; --i) a[parent[i]] += a[i];
    for (int i = 0; i < n; ++i) a[i] = a[i] > 0;
    for (int i = 1; i < n; ++i) a[parent[i]] ^= a[i];
    std::vector<int> v;
    for (int i = 0; i < n; ++i)
        if (a[i]) v.push_back(dep[i]);
    
    int ans = 0;
    std::sort(v.begin(), v.end());
    for (int l = 0; l < int(v.size()); ) {
        int r = l;
        while (r < int(v.size()) && v[l] == v[r]) ++r;
        if ((r - l) % 2 == 1) ++ans;
        l = r;
    }
    
    std::cout << ans << "\n";
    
    return 0;
}