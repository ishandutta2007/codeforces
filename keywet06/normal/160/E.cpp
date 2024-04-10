#include <bits/stdc++.h>

using namespace std;

const int N = 400005;
const int M = N << 2;

struct node {
    int l, r, t, id;
    bool operator<(const node it) const {
        return l == it.l ? id < it.id : l < it.l;
    }
};

int n, m, t[N], tr[M];
node a[N];

void pushup(int rt) {
    if (a[tr[rt << 1]].r > a[tr[rt << 1 | 1]].r) {
        tr[rt] = tr[rt << 1];
    } else {
        tr[rt] = tr[rt << 1 | 1];
    }
}
void update(int rt, int l, int r, int p, int x) {
    if (l == r) {
        if (a[tr[rt]].r < a[x].r) tr[rt] = x;
        return;
    }
    int mid = l + r >> 1;
    if (p <= mid) {
        update(rt << 1, l, mid, p, x);
    } else {
        update(rt << 1 | 1, mid + 1, r, p, x);
    }
    pushup(rt);
}
int query(int rt, int l, int r, int x) {
    if (a[tr[rt]].r < a[x].r || t[r] < a[x].t) return -1;
    if (l == r) return a[tr[rt]].id;
    int mid = l + r >> 1;
    int q = query(rt << 1, l, mid, x);
    return q == -1 ? query(rt << 1 | 1, mid + 1, r, x) : q;
}

int ans[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n + m; ++i) {
        scanf("%d %d %d", &a[i].l, &a[i].r, &a[i].t);
        a[i].id = i;
        t[i] = a[i].t;
    }
    sort(a + 1, a + n + m + 1);
    sort(t + 1, t + n + m + 1);
    for (int i = 1; i <= n + m; ++i) {
        int p = lower_bound(t + 1, t + n + m + 1, a[i].t) - t;
        if (a[i].id <= n) {
            update(1, 1, n + m, p, i);
        } else {
            ans[a[i].id - n] = query(1, 1, n + m, i);
        }
    }
    for (int i = 1; i <= m; ++i) printf("%d%c", ans[i], " \n"[i == m]);
    return 0;
}