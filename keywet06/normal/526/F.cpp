#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 500005;

int n, top1, top2;

int64 ans;

struct chess {
    int x, y;
    bool operator<(const chess &P) const { return x < P.x; }
} c[N], stk1[N], stk2[N];

struct node {
    int Min, tag;
    int64 cnt;
} t[N << 2];

void build(int i, int l, int r) {
    if (l == r) {
        t[i].Min = l;
        t[i].cnt = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    t[i] = t[i << 1];
}

void pushdown(int i) {
    int ls = i << 1, rs = ls | 1;
    t[ls].Min += t[i].tag;
    t[rs].Min += t[i].tag;
    t[ls].tag += t[i].tag;
    t[rs].tag += t[i].tag;
    t[i].tag = 0;
}

void pushup(int i) {
    int ls = i << 1, rs = ls | 1;
    t[i].Min = min(t[ls].Min, t[rs].Min);
    t[i].cnt = 0;
    if (t[i].Min == t[ls].Min) t[i].cnt += t[ls].cnt;
    if (t[i].Min == t[rs].Min) t[i].cnt += t[rs].cnt;
}

void update(int i, int l, int r, int x, int y, int val) {
    if (l >= x && r <= y) {
        t[i].Min += val;
        t[i].tag += val;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(i);
    if (mid >= x) update(i << 1, l, mid, x, y, val);
    if (mid < y) update(i << 1 | 1, mid + 1, r, x, y, val);
    pushup(i);
}

int query(int i, int l, int r, int x, int y) {
    if (l >= x && r <= y) return t[i].Min == 0 ? t[i].cnt : 0;
    int mid = (l + r) >> 1, ans = 0;
    pushdown(i);
    if (mid >= x) ans += query(i << 1, l, mid, x, y);
    if (mid < y) ans += query(i << 1 | 1, mid + 1, r, x, y);
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &c[i].x, &c[i].y);
    sort(c + 1, c + n + 1);
    build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        update(1, 1, n, 1, n, -1);
        while (top1 && stk1[top1].y < c[i].y) {
            update(1, 1, n, stk1[top1 - 1].x + 1, stk1[top1].x,
                   c[i].y - stk1[top1].y),
                --top1;
        }
        stk1[++top1] = {i, c[i].y};
        while (top2 && stk2[top2].y > c[i].y) {
            update(1, 1, n, stk2[top2 - 1].x + 1, stk2[top2].x,
                   stk2[top2].y - c[i].y),
                --top2;
        }
        stk2[++top2] = {i, c[i].y};
        ans += query(1, 1, n, 1, i);
    }
    printf("%lld\n", ans);
    return 0;
}