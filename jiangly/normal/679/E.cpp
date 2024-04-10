#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int MAX_N = 1E5;
constexpr LL INF = 1E18;
void inc(LL &x, LL y) {x = min(INF, x + y);}
int n, q;
LL next_bad[MAX_N];
set<int> good;
struct Node {
    LL lazy, min_dis;
} t[4 * MAX_N];
void pushup(int p) {t[p].min_dis = min(t[2 * p].min_dis, t[2 * p + 1].min_dis);}
void pushdown(int p) {
    inc(t[2 * p].min_dis, t[p].lazy);
    inc(t[2 * p].lazy, t[p].lazy);
    inc(t[2 * p + 1].min_dis, t[p].lazy);
    inc(t[2 * p + 1].lazy, t[p].lazy);
    t[p].lazy = 0;
}
void build(int p, int l, int r) {
    if (r - l == 1) {
        int x;
        cin >> x;
        next_bad[l] = 1;
        while (next_bad[l] < x)
            next_bad[l] *= 42;
        t[p].min_dis = next_bad[l] - x;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid, r);
    pushup(p);
}
LL getVal(int p, int l, int r, int x) {
    if (r - l == 1)
        return next_bad[x] - t[p].min_dis;
    int mid = (l + r) / 2;
    pushdown(p);
    if (x < mid)
        return getVal(2 * p, l, mid, x);
    return getVal(2 * p + 1, mid, r, x);
}
LL getVal(int x) {assert(good.count(x));return getVal(1, 0, n, x);}
void modify(int p, int l, int r, int x, LL y) {
    if (r - l == 1) {
        next_bad[x] = 1;
        while (next_bad[x] < y)
            next_bad[x] *= 42;
        t[p].min_dis = next_bad[x] - y;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(p);
    if (x < mid)
        modify(2 * p, l, mid, x, y);
    else
        modify(2 * p + 1, mid, r, x, y);
    pushup(p);
}
void modify(int x, LL y) {modify(1, 0, n, x, y);}
void rangeAdd(int p, int l, int r, int x, int y, LL v) {
    if (l >= y || r <= x)
        return;
    if (l >= x && r <= y) {
        inc(t[p].min_dis, v);
        inc(t[p].lazy, v);
        return;
    }
    int mid = (l + r) / 2;
    pushdown(p);
    rangeAdd(2 * p, l, mid, x, y, v);
    rangeAdd(2 * p + 1, mid, r, x, y, v);
    pushup(p);
}
void rangeAdd(int l, int r, LL x) {rangeAdd(1, 0, n, l, r, x);}
void correct(int p, int l, int r) {
    if (t[p].min_dis >= 0)
        return;
    if (r - l == 1) {
        LL v = next_bad[l] - t[p].min_dis;
        while (next_bad[l] < v)
            next_bad[l] *= 42;
        t[p].min_dis = next_bad[l] - v;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(p);
    correct(2 * p, l, mid);
    correct(2 * p + 1, mid, r);
    pushup(p);
}
void correct() {correct(1, 0, n);}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        good.insert(i);
    build(1, 0, n);
    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int j;
            cin >> j;
            --j;
            j = *good.lower_bound(j);
            cout << getVal(j) << "\n";
        } else if (op == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            if (l > 0 && !good.count(l - 1)) {
                int j = *good.lower_bound(l - 1);
                modify(l - 1, getVal(j));
                good.insert(l - 1);
            }
            modify(r - 1, x);
            good.insert(r - 1);
            rangeAdd(l, r - 1, INF);
            auto j = good.lower_bound(l);
            while (*j < r - 1) {
                auto k = next(j);
                good.erase(j);
                j = k;
            }
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            if (l > 0 && !good.count(l - 1)) {
                int j = *good.lower_bound(l - 1);
                modify(l - 1, getVal(j));
                good.insert(l - 1);
            }
            if (!good.count(r - 1)) {
                int j = *good.lower_bound(r - 1);
                modify(r - 1, getVal(j));
                good.insert(r - 1);
            }
            do {
                rangeAdd(l, r, -x);
                correct();
            } while (t[1].min_dis == 0);
        }
    }
    return 0;
}