#include <bits/stdc++.h>

constexpr int P = 1000000007;

struct Data {
    int abc, ab, bc, a, b, c;
};
Data operator+(const Data &l, const Data &r) {
    return { int((l.abc + r.abc + int64_t(l.ab) * r.c + int64_t(l.a) * r.bc) % P),
        int((l.ab + r.ab + int64_t(l.a) * r.b) % P),
        int((l.bc + r.bc + int64_t(l.b) * r.c) % P),
        (l.a + r.a) % P, (l.b + r.b) % P, (l.c + r.c) % P };
}

struct SegmentTree {
    int n;
    std::vector<Data> dat;
    SegmentTree(int n) : n(n) {
        int siz = 1;
        while (siz < n) {
            siz *= 2;
        }
        siz *= 2;
        dat.resize(siz);
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                dat[p] = { 0, 0, 0, 0, 0, 0 };
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        dat[p] = dat[2 * p] + dat[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Data &v) {
        if (r - l == 1) {
            dat[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int x, const Data &v) {
        modify(1, 0, n, x, v);
    }
    int get() {
        return dat[1].abc;
    }
};

struct Fenwick {
    int n;
    std::vector<int> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    int sum(int x) {
        int res = 0;
        for (int i = x; i > 0; i &= i - 1) {
            res += a[i - 1];
        }
        return res;
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
    }
    
    std::vector<int> values(a);
    std::sort(values.begin(), values.end());
    values.erase(std::unique(values.begin(), values.end()), values.end());
    
    for (int i = 0; i < n; ++i) {
        a[i] = std::lower_bound(values.begin(), values.end(), a[i]) - values.begin();
    }
    
    int m = values.size();
    std::vector<int> pre(n), suf(n), pos(n), cnt(m);
    
    for (int i = 0; i < n; ++i) {
        pos[i] = cnt[a[i]]++;
    }
    Fenwick fen(m);
    for (int i = 0; i < n; ++i) {
        pre[i] = fen.sum(a[i] + 1);
        fen.add(a[i], 1);
    }
    fen = Fenwick(m);
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = fen.sum(a[i] + 1);
        fen.add(a[i], 1);
    }
    
    std::vector<SegmentTree> trees;
    trees.reserve(m);
    for (int i = 0; i < m; ++i) {
        trees.emplace_back(cnt[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        trees[a[i]].modify(pos[i], {0, 0, 0, pre[i], 1, suf[i]});
    }
    
    int q;
    std::cin >> q;
    
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        ans = (ans + trees[i].get()) % P;
    }
    
    for (int i = 0; i < q; ++i) {
        int opt, x;
        std::cin >> opt >> x;
        --x;
        ans = (ans - trees[a[x]].get() + P) % P;
        if (opt == 1) {
            trees[a[x]].modify(pos[x], {0, 0, 0, 0, 0, 0});
        } else {
            trees[a[x]].modify(pos[x], {0, 0, 0, pre[x], 1, suf[x]});
        }
        ans = (ans + trees[a[x]].get()) % P;
        std::cout << ans << "\n";
    }
    
    return 0;
}