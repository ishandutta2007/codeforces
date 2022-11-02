#include <bits/stdc++.h>

constexpr int N = 1e3;

int n;
int f[N], x[N], y[N];
int l[N], r[N], u[N], d[N];
int p[N];

int find(int x) {
    while (x != f[x])
        x = f[x] = f[f[x]];
    return x;
}

int mx;
int ans = std::numeric_limits<int>::max();

std::tuple<int, int, int> edges[N * N];
int cnte, cnt;

void check() {
    static std::pair<int, int> a[4];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (y[i] == y[j] || x[i] == x[j])
                continue;
            int c = 0;
            a[c++] = {find(i), std::abs(y[i] - y[j])};
            a[c++] = {find(j), std::abs(x[i] - x[j])};
            
            int k = x[i] < x[j] ? l[j] : r[j];
            if (k != -1)
                a[c++] = {find(k), std::abs(x[i] - x[k])};
            
            k = y[i] < y[j] ? u[i] : d[i];
            if (k != -1)
                a[c++] = {find(k), std::abs(y[j] - y[k])};
            
            std::sort(a, a + c);
            
            int f = cnt, res = mx;
            
            for (int k = 0; k < c; ++k) {
                if (k == 0 || a[k].first != a[k - 1].first) {
                    --f;
                    res = std::max(res, a[k].second);
                }
            }
            
            if (f == 0)
                ans = std::min(ans, res);
        }
    }
    
    if (cnt > 2)
        return;
    
    for (int i = 0; i < n; ++i) {
        if (r[i] != -1 && find(i) != find(r[i]))
            ans = std::min(ans, std::max(mx, (x[r[i]] - x[i] + 1) / 2));
        if (u[i] != -1 && find(i) != find(u[i]))
            ans = std::min(ans, std::max(mx, (y[u[i]] - y[i] + 1) / 2));
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n;
    
    std::iota(f, f + n, 0);
    
    for (int i = 0; i < n; ++i)
        std::cin >> x[i] >> y[i];
    
    std::iota(p, p + n, 0);
    std::sort(p, p + n, [&](int i, int j) {
        return y[i] < y[j];
    });
    std::map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int j = p[i];
        d[j] = mp.count(x[j]) ? mp[x[j]] : -1;
        mp[x[j]] = j;
    }
    mp.clear();
    for (int i = n - 1; i >= 0; --i) {
        int j = p[i];
        u[j] = mp.count(x[j]) ? mp[x[j]] : -1;
        mp[x[j]] = j;
    }
    std::sort(p, p + n, [&](int i, int j) {
        return x[i] < x[j];
    });
    mp.clear();
    for (int i = 0; i < n; ++i) {
        int j = p[i];
        l[j] = mp.count(y[j]) ? mp[y[j]] : -1;
        mp[y[j]] = j;
    }
    mp.clear();
    for (int i = n - 1; i >= 0; --i) {
        int j = p[i];
        r[j] = mp.count(y[j]) ? mp[y[j]] : -1;
        mp[y[j]] = j;
    }
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (x[i] == x[j] || y[i] == y[j])
                edges[cnte++] = std::make_tuple(std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]), i, j);
    
    std::sort(edges, edges + cnte);
    
    cnt = n;
    
    if (n <= 4)
        check();
    
    for (int i = 0; i < cnte; ++i){
        auto [w, u, v] = edges[i];
        u = find(u);
        v = find(v);
        if (u == v)
            continue;
        
        f[u] = v;
        mx = w;
        --cnt;
        if (cnt <= 4)
            check();
    }
    
    if (cnt == 1)
        ans = std::min(ans, mx);
    
    if (ans == std::numeric_limits<int>::max())
        ans = -1;
    
    std::cout << ans << "\n";
    
    return 0;
}