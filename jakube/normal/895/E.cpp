#include <bits/stdc++.h>
using namespace std;

struct Segment {
    double sum = 0;
    int size = 0;
    bool todo = false;
    double m1 = 1;
    double m2 = 0;
};

class SegmentTreeRecLazy
{
public:
    SegmentTreeRecLazy(vector<int> v) : n(v.size())
    {
        data.resize(4 * n);
        build(v);
    }

    double build(vector<int>& v, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (l + 1 == r) {
            data[id].size = 1;
            return data[id].sum = v[l];
        } else {
            int m = (l + r) >> 1;
            data[id].sum =
                build(v, id << 1, l, m) + build(v, id << 1 | 1, m, r);
            data[id].size = data[id << 1].size + data[id << 1 | 1].size;
            return data[id].sum;
        }
    }

    double sum(int x, int y, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
            return 0;
        } else if (x <= l && r <= y) {
            return data[id].sum;
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            return sum(x, y, id << 1, l, m) + sum(x, y, id << 1 | 1, m, r);
        }
    }

    void update(int x, int y, double mult, double add, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
        } else if (x <= l && r <= y) {
            auto& cur = data[id];
            cur.m1 *= mult;
            cur.m2 *= mult;
            cur.m2 += add;
            cur.sum = cur.sum * mult + cur.size * add;
            cur.todo = true;
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            update(x, y, mult, add, id << 1, l, m);
            update(x, y, mult, add, id << 1 | 1, m, r);
            data[id].sum = data[id << 1].sum + data[id << 1 | 1].sum;
        }
    }

    void apply(int id)
    {
        // afterwards
        // a..b  c..d
        // v1 * (l1-1)/l1 + sum2/l2/l1
        // segment
        // sum1 * (l1 - 1) / l1 + sum2/l2/l1 * l_seg1
        auto& old = data[id >> 1];
        auto& cur = data[id];

        cur.m1 *= old.m1;
        cur.m2 *= old.m1;
        cur.m2 += old.m2;
        cur.sum = cur.sum * old.m1 + cur.size * old.m2;
        cur.todo = true;
    }

private:
    void push(int id, int l, int r)
    {
        if (data[id].todo && l + 1 < r) {
            apply(id << 1);
            apply(id << 1 | 1);
            data[id].todo = false;
            data[id].m1 = 1;
            data[id].m2 = 0;
        }
    }

    int n;
    std::vector<Segment> data;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout << std::fixed << std::setprecision(7);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegmentTreeRecLazy segtree(a);

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            auto s1 = segtree.sum(l1 - 1, r1);
            auto s2 = segtree.sum(l2 - 1, r2);
            double L1 = r1 - l1 + 1;
            double L2 = r2 - l2 + 1;
            segtree.update(l1 - 1, r1, (L1 - 1) / L1, s2 / L1 / L2);
            segtree.update(l2 - 1, r2, (L2 - 1) / L2, s1 / L1 / L2);
        } else {
            int l, r;
            cin >> l >> r;
            cout << segtree.sum(l - 1, r) << '\n';
        }
    }
}