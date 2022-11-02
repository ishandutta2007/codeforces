#include <bits/stdc++.h>

const int P = 1000000007;
const int I2 = (P + 1) / 2;

struct Data {
    int pow, vl, vr, val;
    Data(int pow = 1, int vl = 0, int vr = 0, int val = 0) : pow(pow), vl(vl), vr(vr), val(val) {}
    friend Data operator+(const Data &a, const Data &b) {
        return Data(1ll * a.pow * b.pow % P, (a.vl + 1ll * a.pow * b.vl) % P, (1ll * a.vr * b.pow + b.vr) % P, (1ll * a.val * b.pow + 1ll * a.pow * b.val + 1ll * a.vl * b.vr) % P);
    }
};

struct SegmentTree {
    int n;
    std::vector<Data> a;
    std::vector<int> val;
    void build(int p, int l, int r) {
        if (r - l == 1)
            return;
        int m = (l + r) / 2;
        build(2 * p, l, m);
        build(2 * p + 1, m, r);
        a[p] = a[2 * p] + a[2 * p + 1];
    }
    void init(int _n, const std::vector<std::pair<int, int>> &v) {
        n = _n;
        val.resize(n);
        for (int i = 0; i < n; ++i)
            val[i] = v[i].first;
        a.resize(4 * n);
        build(1, 0, n);
    }
    void modify(int p, int l, int r, int pos, int op) {
        if (r - l == 1) {
            if (op == 1) {
                a[p] = Data(2, val[l], val[l], 0);
            } else {
                a[p] = Data();
            }
            return;
        }
        int m = (l + r) / 2;
        if (pos < m) {
            modify(2 * p, l, m, pos, op);
        } else {
            modify(2 * p + 1, m, r, pos, op);
        }
        a[p] = a[2 * p] + a[2 * p + 1];
    }
    void modify(int pos, int op) {
        modify(1, 0, n, pos, op);
    }
};

int n, q;

std::vector<int> p, pos, val;

std::vector<std::pair<int, int>> v;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    int inv = 1;
    for (int i = 0; i < n; ++i)
        inv = 1ll * inv * I2 % P;
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        v.emplace_back(p[i], i);
    }
    std::cin >> q;
    pos.resize(q);
    val.resize(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> pos[i] >> val[i];
        --pos[i];
        v.emplace_back(val[i], n + i);
    }
    std::sort(v.begin(), v.end());
    SegmentTree t;
    t.init(v.size(), v);
    for (int i = 0; i < n; ++i) {
        p[i] = std::lower_bound(v.begin(), v.end(), std::make_pair(p[i], i)) - v.begin();
        t.modify(p[i], 1);
    }
    std::cout << 1ll * t.a[1].val * inv % P << "\n";
    for (int i = 0; i < q; ++i) {
        t.modify(p[pos[i]], 0);
        p[pos[i]] = std::lower_bound(v.begin(), v.end(), std::make_pair(val[i], n + i)) - v.begin();
        t.modify(p[pos[i]], 1);
        std::cout << 1ll * t.a[1].val * inv % P << "\n";
    }
    return 0;
}