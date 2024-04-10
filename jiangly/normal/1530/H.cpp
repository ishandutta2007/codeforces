#include <bits/stdc++.h>

using i64 = long long;

constexpr int L = 600;

struct Fenwick {
    const int n;
    std::vector<int> a;
    Fenwick(int n) : n(n), a(n, -1) {}
    void add(int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = std::max(a[i - 1], v);
        }
    }
    int query(int x) {
        int ans = -1;
        for (int i = x; i > 0; i -= i & -i) {
            ans = std::max(ans, a[i - 1]);
        }
        return ans;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    
    std::reverse(a.begin(), a.end());
    
    int ans = 1;
    
    for (int t = 0; t < 2; t++) {
        std::vector f(n, std::vector(L, -1)), g(n, std::vector(L, n));
        
        std::vector t1(L, Fenwick(n)), t2(t1), t3(t1), t4(t1);
        
        if (t == 0) {
            t1[1].add(a[0], a[0]);
            t2[1].add(n - 1 - a[0], n - 1 - a[0]);
            f[0][1] = a[0];
            g[0][1] = a[0];
        }
        
        for (int i = 1; i < n; i++) {
            if (t == 1) {
                f[i][2] = a[i];
                g[i][2] = a[i];
                t1[2].add(a[i], a[i]);
                t2[2].add(n - 1 - a[i], n - 1 - a[i]);
            }
            for (int j = 2; j < L; j++) {
                f[i][j] = t1[j - 1].query(a[i]);
                g[i][j] = n - 1 - t2[j - 1].query(n - 1 - a[i]);
                
                int x = i - j + 1;
                if (x >= 0 && g[x][j - 1] < n) {
                    t3[j - 1].add(g[x][j - 1], a[x]);
                }
                if (x >= 0 && f[x][j - 1] >= 0) {
                    t4[j - 1].add(n - 1 - f[x][j - 1], n - 1 - a[x]);
                }
                f[i][j] = std::max(f[i][j], t3[j - 1].query(a[i]));
                g[i][j] = std::min(g[i][j], n - 1 - t4[j - 1].query(n - 1 - a[i]));
                
                if (f[i][j] >= 0 || g[i][j] < n) {
                    ans = std::max(ans, j - t);
                }
            }
            for (int j = 2; j < L; j++) {
                if (f[i][j] >= 0) {
                    t1[j].add(a[i], f[i][j]);
                }
                if (g[i][j] < n) {
                    t2[j].add(n - 1 - a[i], n - 1 - g[i][j]);
                }
            }
        }
    }
    
    std::cout << ans << "\n";
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