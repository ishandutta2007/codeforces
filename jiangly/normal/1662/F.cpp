#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1 << 20;

std::vector<std::array<int, 2>> f[N];
std::array<int, 2> mx[N];

void rangeAdd(int p, int l, int r, int x, int y, int v, int t) {
    if (l >= y || r <= x) {
        return;
    }
    if (l >= x && r <= y) {
        f[p].push_back({v, t});
        return;
    }
    int m = (l + r) / 2;
    rangeAdd(2 * p, l, m, x, y, v, t);
    rangeAdd(2 * p + 1, m, r, x, y, v, t);
}

void pull(int p) {
    mx[p] = std::max(mx[2 * p], mx[2 * p + 1]);
}

void build(int p, int l, int r, auto &a) {
    f[p].clear();
    if (r - l == 1) {
        mx[p] = {a[l], l};
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m, a);
    build(2 * p + 1, m, r, a);
    pull(p);
}

void modify(int p, int l, int r, int x) {
    if (r - l == 1) {
        mx[p] = {-1, -1};
        return;
    }
    int m = (l + r) / 2;
    if (x < m) {
        modify(2 * p, l, m, x);
    } else {
        modify(2 * p + 1, m, r, x);
    }
    pull(p);
}

std::array<int, 2> rangeMax(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x) {
        return {-1, -1};
    }
    if (l >= x && r <= y) {
        return mx[p];
    }
    int m = (l + r) / 2;
    return std::max(rangeMax(2 * p, l, m, x, y), rangeMax(2 * p + 1, m, r, x, y));
}

void find(int p, int l, int r, int x, int u, auto g) {
    while (!f[p].empty() && f[p].back()[0] <= u) {
        g(f[p].back()[1]);
        f[p].pop_back();
    }
    if (r - l == 1) {
        return;
    }
    int m = (l + r) / 2;
    if (x < m) {
        find(2 * p, l, m, x, u, g);
    } else {
        find(2 * p + 1, m, r, x, u, g);
    }
}

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    a--;
    b--;
    
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    
    build(1, 0, n, p);
    
    std::vector<int> dis(n, -1);
    dis[a] = 0;
    std::queue<int> q;
    q.push(a);
    
    std::vector<int> f(n);
    std::iota(f.begin(), f.end(), 0);
    std::sort(f.begin(), f.end(), [&](int i, int j) { return p[i] > p[j]; });
    for (auto i : f) {
        rangeAdd(1, 0, n, std::max(0, i - p[i]), std::min(n, i + p[i] + 1), p[i], i);
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        int l = std::max(0, u - p[u]), r = std::min(n, u + p[u] + 1);
        while (true) {
            auto [pv, v] = rangeMax(1, 0, n, l, r);
            if (pv < p[u]) {
                break;
            }
            modify(1, 0, n, v);
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
        
        find(1, 0, n, u, p[u], [&](auto x) {
            if (dis[x] == -1) {
                dis[x] = dis[u] + 1;
                q.push(x);
            }
        });
    }
    
    std::cout << dis[b] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}