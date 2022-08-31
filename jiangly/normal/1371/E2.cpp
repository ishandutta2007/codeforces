#include <bits/stdc++.h>
struct SegmentTree {
    int n;
    std::vector<int> mn, tag;
    SegmentTree(int n) : n(n), mn(4 * n), tag(4 * n) {}
    void add(int p, int v) {
        mn[p] += v;
        tag[p] += v;
    }
    void push(int p) {
        add(2 * p, tag[p]);
        add(2 * p + 1, tag[p]);
        tag[p] = 0;
    }
    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) {
            return;
        } else if (l >= x && r <= y) {
            add(p, v);
        } else {
            int m = (l + r) / 2;
            push(p);
            rangeAdd(2 * p, l, m, x, y, v);
            rangeAdd(2 * p + 1, m, r, x, y, v);
            mn[p] = std::min(mn[2 * p], mn[2 * p + 1]);
        }
    }
    void rangeAdd(int l, int r, int v) {
        rangeAdd(1, 0, n, l, r, v);
    }
    void search(int p, int l, int r, int x, int y, std::vector<int> &a) {
        if (l >= y || r <= x || mn[p] > 0) {
            return;
        } else if (r - l == 1) {
            a.push_back(l);
        } else {
            int m = (l + r) / 2;
            push(p);
            search(2 * p, l, m, x, y, a);
            search(2 * p + 1, m, r, x, y, a);
        }
    }
    void search(int l, int r, std::vector<int> &a) {
        search(1, 0, n, l, r, a);
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, p;
    std::cin >> n >> p;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());
    std::vector<std::tuple<int, int, int, int>> opt;
    for (int i = 0, j; i < n; i = j) {
        for (j = i; j < n && a[i] == a[j]; ++j)
            ;
        int x = j % p;
        int maxi = (n - x - 1) / p * p + x;
        if (j == n || a[j] - a[i] >= p) {
            opt.emplace_back(a[i] - maxi, 0, p, 1);
            if (j < n)
                opt.emplace_back(a[j] - x, 0, p, -1);
        } else {
            int l = a[i] - maxi;
            int r = a[j] - x;
            int ml = (l % p + p) % p;
            int mr = (r % p + p) % p;
            if (ml < mr) {
                opt.emplace_back(l, ml, mr, 1);
                opt.emplace_back(r, ml, mr, -1);
            } else {
                opt.emplace_back(l, ml, p, 1);
                opt.emplace_back(l, 0, mr, 1);
                opt.emplace_back(r, ml, p, -1);
                opt.emplace_back(r, 0, mr, -1);
            }
        }
    }
    std::sort(opt.begin(), opt.end());
    std::vector<int> ans;
    SegmentTree t(p);
    for (int i = 0; i < int(opt.size()) - 1; ++i) {
        auto [x, l, r, v] = opt[i];
        t.rangeAdd(l, r, v);
        int y = std::get<0>(opt[i + 1]);
        if (y <= a[0] || x == y)
            continue;
        x = std::max(a[0], x);
        std::vector<int> can;
        if (y - x >= p) {
            t.search(0, p, can);
        } else if (y % p > x % p) {
            t.search(x % p, y % p, can);
        } else {
            t.search(x % p, p, can);
            t.search(0, y % p, can);
        }
        for (auto j : can)
            for (int k = (x - j + p - 1) / p * p + j; k < y; k += p)
                ans.push_back(k);
    }
    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << "\n";
    for (auto i : ans)
        std::cout << i << " \n"[i == ans.back()];
    return 0;
}