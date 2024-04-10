#include <bits/stdc++.h>

struct Fenwick {
    int n, lg;
    std::vector<int> a;
    Fenwick(int n) : n(n), lg(std::__lg(n)), a(n) {}
    void add(int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    int select(int k) {
        int x = 0;
        for (int i = lg; i >= 0; --i) {
            if (x + (1 << i) <= n && k >= a[x + (1 << i) - 1]) {
                x += 1 << i;
                k -= a[x - 1];
            }
        }
        if (x == n) {
            return -1;
        } else {
            return x;
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
    }
    
    std::vector<int> next(n), last(n, -1);
    for (int i = n - 1; i >= 0; --i) {
        next[i] = last[a[i]];
        last[a[i]] = i;
    }
    
    Fenwick fen(n);
    
    for (int i = 0; i < n; ++i) {
        if (last[i] != -1) {
            fen.add(last[i], 1);
        }
    }
    
    std::vector<int> ans(n);
    std::vector<std::vector<int>> f(n);
    for (int i = 1; i <= n; ++i) {
        f[0].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        for (auto k : f[i]) {
            ++ans[k - 1];
            int x = fen.select(k);
            if (x != -1) {
                f[x].push_back(k);
            }
        }
        fen.add(i, -1);
        if (next[i] != -1) {
            fen.add(next[i], 1);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
    
    return 0;
}