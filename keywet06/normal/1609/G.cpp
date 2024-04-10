#include <bits/stdc++.h>

using int64 = long long;

constexpr int N = 1 << 18;

struct Info {
    int mn;
    int mx;
    int len;
    int64 sum;
    int64 isum;
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.mn = a.mn;
    c.mx = b.mx;
    c.len = a.len + b.len;
    c.sum = a.sum + b.sum;
    c.isum = a.isum + b.isum + a.len * b.sum;
    return c;
}

Info info[N];
int64 tag[N];

void build(int p, int l, int r) {
    if (r - l == 1) {
        info[p] = {0, 0, 1, 0LL, 0LL};
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m, r);
    info[p] = info[2 * p] + info[2 * p + 1];
}

void add(int p, int64 v) {
    tag[p] += v;
    info[p].mn += v;
    info[p].mx += v;
    info[p].sum += v * info[p].len;
    info[p].isum += v * info[p].len * (info[p].len - 1) / 2;
}

void push(int p) {
    if (tag[p] == 0) {
        return;
    }
    add(2 * p, tag[p]);
    add(2 * p + 1, tag[p]);
    tag[p] = 0;
}

void rangeAdd(int p, int l, int r, int x, int64 v) {
    if (r <= x) return;
    if (l >= x) return add(p, v);
    ;
    int m = (l + r) / 2;
    push(p);
    rangeAdd(2 * p, l, m, x, v);
    rangeAdd(2 * p + 1, m, r, x, v);
    info[p] = info[2 * p] + info[2 * p + 1];
}

int get(int p, int l, int r, int64 v) {
    if (info[p].mn > v) return 0;
    if (info[p].mx <= v) return info[p].len;
    int m = (l + r) / 2;
    push(p);
    return get(2 * p, l, m, v) + get(2 * p + 1, m, r, v);
}

Info rangeQuery(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x) return {0, 0, 0, 0, 0};
    if (l >= x && r <= y) return info[p];
    int m = (l + r) / 2;
    push(p);
    return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int64> a(n), b(m);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < m; ++i) std::cin >> b[i];
    int64 a0 = a[0], b0 = b[0];
    std::vector<int64> da(n - 1), db(m - 1);
    for (int i = 0; i < n - 1; ++i) da[i] = a[i + 1] - a[i];
    for (int i = 0; i < m - 1; ++i) db[i] = b[i + 1] - b[i];
    build(1, 0, m - 1);
    int64 lst = 0;
    for (int i = 0; i < m - 1; ++i) rangeAdd(1, 0, m - 1, i, db[i] - lst), lst = db[i];
    while (q--) {
        int t, k, d;
        std::cin >> t >> k >> d;
        if (t == 1) {
            if (k == n) a0 += d, --k;
            for (int i = n - 1 - k; i < n - 1; ++i) da[i] += d;
        } else {
            if (k == m) b0 += d, --k;
            rangeAdd(1, 0, m - 1, m - 1 - k, d);
        }
        int64 ans = (a0 + b0) * (n + m - 1);
        int j = 0;
        for (int i = 0; i < n - 1; ++i) {
            int x = get(1, 0, m - 1, da[i]);
            auto r = rangeQuery(1, 0, m - 1, j, x);
            ans += da[i] * (n + m - 2 - (i + x));
            ans += r.sum * (n + m - 2 - (i + j)) - r.isum;
            j = x;
        }
        auto r = rangeQuery(1, 0, m - 1, j, m - 1);
        ans += r.sum * (n + m - 2 - (n - 1 + j)) - r.isum;
        std::cout << ans << "\n";
    }
    return 0;
}