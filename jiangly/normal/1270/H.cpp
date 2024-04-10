#include <bits/stdc++.h>
using namespace std;
constexpr int C = 1'000'001;
struct Node {
    int min, cnt;
    Node() {}
    Node(int min, int cnt) : min(min), cnt(cnt) {}
};
Node operator+(const Node &lhs, const Node &rhs) {
    if (lhs.min < rhs.min) {
        return lhs;
    } else if (lhs.min > rhs.min) {
        return rhs;
    } else {
        return Node(lhs.min, lhs.cnt + rhs.cnt);
    }
}
Node t[4 * C];
int lazy[4 * C], d[C + 1], act[C];
void add(int p, int v) {
    t[p].min += v;
    lazy[p] += v;
}
void push(int p) {
    add(2 * p, lazy[p]);
    add(2 * p + 1, lazy[p]);
    lazy[p] = 0;
}
void build(int p, int l, int r) {
    if (r - l == 1) {
        t[p] = Node(d[l], act[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m, r);
    t[p] = t[2 * p] + t[2 * p + 1];
}
void rangeAdd(int p, int l, int r, int x, int y, int v) {
    if (l >= y || r <= x)
        return;
    if (l >= x && r <= y) {
        add(p, v);
        return;
    }
    int m = (l + r) / 2;
    push(p);
    rangeAdd(2 * p, l, m, x, y, v);
    rangeAdd(2 * p + 1, m, r, x, y, v);
    t[p] = t[2 * p] + t[2 * p + 1];
}
void rangeAdd(int l, int r, int v) {
    if (l > r)
        swap(l, r);
    rangeAdd(1, 0, C, l, r, v);
}
void setActivity(int p, int l, int r, int x, int v) {
    if (r - l == 1) {
        t[p].cnt = v;
        return;
    }
    int m = (l + r) / 2;
    push(p);
    if (x < m) {
        setActivity(2 * p, l, m, x, v);
    } else {
        setActivity(2 * p + 1, m, r, x, v);
    }
    t[p] = t[2 * p] + t[2 * p + 1];
}
void setActivity(int x, int v) {
    setActivity(1, 0, C, x, v);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2);
    a[0] = C;
    a[n + 1] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i <= n; ++i) {
        int l = a[i], r = a[i + 1];
        if (l > r)
            swap(l, r);
        ++d[l];
        --d[r];
    }
    for (int i = 1; i <= C; ++i)
        d[i] += d[i - 1];
    for (int i = 1; i < n + 2; ++i)
        act[a[i]] = 1;
    build(1, 0, C);
    for (int i = 0; i < q; ++i) {
        int x, v;
        cin >> x >> v;
        setActivity(a[x], false);
        setActivity(v, true);
        rangeAdd(a[x - 1], a[x], -1);
        rangeAdd(a[x], a[x + 1], -1);
        rangeAdd(a[x - 1], v, 1);
        rangeAdd(v, a[x + 1], 1);
        a[x] = v;
        cout << t[1].cnt - 1 << "\n";
    }
    return 0;
}