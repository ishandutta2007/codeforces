#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, x;
    std::cin >> n >> m >> x;
    x++;
    
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    
    i64 ans = 0;
    
    std::vector<int> c(n, x + 1), d(m, x + 1);
    std::vector<int> s, v;
    for (int i = 0; i < n; i++) {
        int u = 0;
        while (!s.empty() && a[i] < a[s.back()]) {
            u = std::max(u, v.back());
            s.pop_back();
            v.pop_back();
        }
        u = std::max(u, a[i]);
        if (!s.empty()) {
            c[i] = std::min(c[i], u);
        }
        s.push_back(i);
        v.push_back(u);
    }
    s = v = {};
    for (int i = n - 1; i >= 0; i--) {
        int u = 0;
        while (!s.empty() && a[i] <= a[s.back()]) {
            u = std::max(u, v.back());
            s.pop_back();
            v.pop_back();
        }
        u = std::max(u, a[i]);
        if (!s.empty()) {
            c[i] = std::min(c[i], u);
        }
        s.push_back(i);
        v.push_back(u);
    }
    
    s = v = {};
    for (int i = 0; i < m; i++) {
        int u = 0;
        while (!s.empty() && b[i] < b[s.back()]) {
            u = std::max(u, v.back());
            s.pop_back();
            v.pop_back();
        }
        u = std::max(u, b[i]);
        if (!s.empty()) {
            d[i] = std::min(d[i], u);
        }
        s.push_back(i);
        v.push_back(u);
    }
    s = v = {};
    for (int i = m - 1; i >= 0; i--) {
        int u = 0;
        while (!s.empty() && b[i] <= b[s.back()]) {
            u = std::max(u, v.back());
            s.pop_back();
            v.pop_back();
        }
        u = std::max(u, b[i]);
        if (!s.empty()) {
            d[i] = std::min(d[i], u);
        }
        s.push_back(i);
        v.push_back(u);
    }
    
    Fenwick<int> fen(N);
    std::vector<int> p(n), q(m);
    std::iota(p.begin(), p.end(), 0);
    std::iota(q.begin(), q.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) { return a[i] < a[j]; });
    std::sort(q.begin(), q.end(), [&](int i, int j) { return d[i] > d[j]; });
    
    for (int i = 0, j = 0; i < n; i++) {
        while (j < m && a[p[i]] + d[q[j]] >= x) {
            fen.add(b[q[j]], 1);
            j++;
        }
        ans += fen.rangeSum(std::max(0, x - c[p[i]]), std::max(0, x - a[p[i]]));
    }
    
    std::cout << ans << "\n";
    
    return 0;
}