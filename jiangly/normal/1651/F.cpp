#include <bits/stdc++.h>

using i64 = long long;

struct Tree {
    Tree *l;
    Tree *r;
    i64 sc;
    i64 sr;
    Tree() : l(nullptr), r(nullptr), sc(0), sr(0) {}
};

Tree *null = new Tree();

Tree *newTree() {
    Tree *t = new Tree();
    t->l = t->r = null;
    return t;
}

Tree *add(Tree *t, int l, int r, int x, int C, int R) {
    Tree *p = newTree();
    *p = *t;
    
    p->sc += C;
    p->sr += R;
    if (r - l != 1) {
        int m = (l + r) / 2;
        if (x < m) {
            p->l = add(p->l, l, m, x, C, R);
        } else {
            p->r = add(p->r, m, r, x, C, R);
        }
    }
    
    return p;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    null->l = null->r = null;
    
    int n;
    std::cin >> n;
    
    std::vector<int> c(n), r(n), full(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i] >> r[i];
        full[i] = c[i] / r[i];
    }
    
    std::vector<std::array<int, 4>> towers;
    for (int i = n - 1; i >= 0; i--) {
        towers.push_back({i, i + 1, 0, c[i]});
    }
    
    std::vector<int> p(n), vp(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) {
        return full[i] < full[j];
    });
    
    std::vector<Tree *> tree(n + 1);
    tree[0] = null;
    for (int i = 0; i < n; i++) {
        vp[i] = full[i];
        int j = p[i];
        tree[i + 1] = add(tree[i], 0, n, j, c[j], r[j]);
    }
    std::sort(vp.begin(), vp.end());
    
    auto search = [&](auto self, Tree *t, Tree *a, int l, int r, int L, int R, int dt, i64 &h) -> int {
        if (l >= R || r <= L) {
            return R;
        }
        if (l >= L && r <= R) {
            i64 v = t->sc + (a->sr - t->sr) * dt;
            if (v <= h) {
                h -= v;
                return R;
            }
            if (r - l == 1) {
                return l;
            }
        }
        int m = (l + r) / 2;
        int res = self(self, t->l, a->l, l, m, L, R, dt, h);
        if (res < R) {
            return res;
        }
        res = self(self, t->r, a->r, m, r, L, R, dt, h);
        return res;
    };
    
    int q;
    std::cin >> q;
    
    i64 ans = 0;
    while (q--) {
        int t;
        i64 h;
        std::cin >> t >> h;
        
        int pass = 0;
        while (!towers.empty()) {
            auto [L, R, lst, res] = towers.back();
            
            if (res > 0) {
                int cur = std::min(1LL * (t - lst) * r[L] + res, 1LL * c[L]);
                if (cur >= h) {
                    cur -= h;
                    towers.back() = {L, R, t, cur};
                    h = 0;
                    break;
                }
                h -= cur;
                pass = R;
                towers.pop_back();
            } else {
                int x = std::lower_bound(vp.begin(), vp.end(), t - lst) - vp.begin();
                auto j = search(search, tree[x], tree[n], 0, n, L, R, t - lst, h);
                // sum i in [L,R) min(c[i], r[i] * dt)
                // dt <= full[i] -> r[i] * dt
                // dt > full[i] -> c[i]
                
                if (j < R) {
                    pass = j;
                    towers.pop_back();
                    int cur = std::min(1LL * (t - lst) * r[j] + res, 1LL * c[j]);
                    cur -= h;
                    h = 0;
                    if (j + 1 < R) {
                        towers.push_back({j + 1, R, lst, 0});
                    }
                    towers.push_back({j, j + 1, t, cur});
                    break;
                }
                
                pass = R;
                towers.pop_back();
            }
        }
        
        towers.push_back({0, pass, t, 0});
        // for (int i = pass - 1; i >= 0; i--) {
        //     towers.push_back({i, i + 1, t, 0});
        // }
        
        ans += h;
    }
    
    std::cout << ans << "\n";
    
    return 0;
}