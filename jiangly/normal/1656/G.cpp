#include <bits/stdc++.h>

using i64 = long long;
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

void solve() {
    i64 n;
    std::cin >> n;
    
    std::vector<int> a(n);
    std::vector<int> cnt(n);
    std::vector<std::vector<int>> pos(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
        pos[a[i]].push_back(i);
    }
    
    int odd = 0;
    for (int i = 0; i < n; i++) {
        odd += cnt[i] % 2;
    }
    if (odd > 1) {
        std::cout << "NO\n";
        return;
    }
    if (n % 2 == 1 && cnt[a[(n - 1) / 2]] == 1) {
        std::cout << "NO\n";
        return;
    }
    std::cout << "YES\n";
    
    std::vector<int> p(n), q(n);
    
    DSU g(n);
    for (int x = 0, L = 0, R = n; x < 2; x++) {
        for (int i = 0; i < n; i++) {
            if (int(pos[i].size()) % 2 == x) {
                for (auto j : pos[i]) {
                    if (L < n - R) {
                        p[L++] = j;
                    } else {
                        p[--R] = j;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        q[p[i]] = i;
        g.merge(i, p[i]);
    }
    
    auto swap = [&](int x, int y) {
        std::swap(q[p[x]], q[p[y]]);
        std::swap(p[x], p[y]);
    };
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < int(pos[i].size()); j++) {
            int x = pos[i][j];
            int y = pos[i][j - 1];
            if (g.leader(x) != g.leader(y)) {
                swap(q[x], q[y]);
                g.merge(x, y);
            }
        }
    }
    
    int lst = -1;
    for (int i = 0; i < n; i++) {
        if (int(pos[i].size()) <= 1) {
            continue;
        }
        if (lst != -1 && !g.same(pos[i][0], pos[lst][0])) {
            int x = pos[lst][0];
            if (q[x] * 2 + 1 == n) {
                x = pos[lst][1];
            }
            int u = q[x];
            int v = n - 1 - q[x];
            swap(u, v);
            int y = pos[i][0];
            if (q[y] * 2 + 1 == n) {
                y = pos[i][1];
            }
            int a = q[y];
            int b = n - 1 - q[y];
            swap(u, a);
            swap(v, b);
            g.merge(pos[i][0], pos[lst][0]);
        }
        lst = i;
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << p[i] + 1 << " \n"[i == n - 1];
    }
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