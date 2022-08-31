#include <bits/stdc++.h>
using namespace std;
struct Node {
    static int k;
    int id[5], cnt[5];
    Node() : id{}, cnt{} {}
    void insert(int newId, int newCnt) {
        if (newCnt == 0)
            return;
        for (int i = 0; i < k; ++i) {
            if (id[i] == newId && cnt[i] > 0) {
                cnt[i] += newCnt;
                return;
            }
        }
        int l = min_element(cnt, cnt + k) - cnt;
        int c = min(cnt[l], newCnt);
        for (int i = 0; i < k; ++i)
            cnt[i] -= c;
        if (newCnt > c) {
            id[l] = newId;
            cnt[l] = newCnt - c;
        }
    }
};
Node operator+(Node lhs, const Node &rhs) {
    for (int i = 0; i < Node::k; ++i)
        lhs.insert(rhs.id[i], rhs.cnt[i]);
    return lhs;
}
struct SegmentTree {
    int n;
    vector<Node> t;
    vector<int> lazy;
    SegmentTree(const vector<int> &a) : n(a.size()), t(4 * n), lazy(4 * n, -1) {
        build(1, 0, n, a);
    }
    void build(int p, int l, int r, const vector<int> &a) {
        if (r - l == 1) {
            t[p].id[0] = a[l];
            t[p].cnt[0] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * p, l, mid, a);
        build(2 * p + 1, mid, r, a);
        t[p] = t[2 * p] + t[2 * p + 1];
    }
    void cover(int p, int l, int r, int v) {
        lazy[p] = v;
        fill(t[p].cnt + 1, t[p].cnt + Node::k, 0);
        t[p].id[0] = v;
        t[p].cnt[0] = r - l;
    }
    void push(int p, int l, int r) {
        if (lazy[p] != -1) {
            int mid = (l + r) / 2;
            cover(2 * p, l, mid, lazy[p]);
            cover(2 * p + 1, mid, r, lazy[p]);
            lazy[p] = -1;
        }
    }
    void rangeCover(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x)
            return;
        if (l >= x && r <= y) {
            cover(p, l, r, v);
            return;
        }
        int mid = (l + r) / 2;
        push(p, l, r);
        rangeCover(2 * p, l, mid, x, y, v);
        rangeCover(2 * p + 1, mid, r, x, y, v);
        t[p] = t[2 * p] + t[2 * p + 1];
    }
    void rangeCover(int x, int y, int v) {
        rangeCover(1, 0, n, x, y, v);
    }
    Node rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x)
            return Node();
        if (l >= x && r <= y)
            return t[p];
        int mid = (l + r) / 2;
        push(p, l, r);
        return rangeQuery(2 * p, l, mid, x, y) + rangeQuery(2 * p + 1, mid, r, x, y);
    }
    Node rangeQuery(int x, int y) {
        return rangeQuery(1, 0, n, x, y);
    }
};
int Node::k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    Node::k = 100 / p;
    SegmentTree t(a);
    for (int i = 0; i < m; ++i) {
        int op, l, r;
        cin >> op >> l >> r;
        --l;
        if (op == 1) {
            int id;
            cin >> id;
            t.rangeCover(l, r, id);
        } else {
            cout << Node::k;
            auto ans = t.rangeQuery(l, r);
            for (int j = 0; j < Node::k; ++j)
                cout << " " << ans.id[j];
            cout << "\n";
        }
    }
    return 0;
}