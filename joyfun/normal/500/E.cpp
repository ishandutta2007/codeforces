#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;

struct query {
    int l, r, id;
} s[N], q[N];

int n, ans[N];

bool cmp(query a, query b) {
    return a.l > b.l;
}

int hash[N * 2], hn;

int find(int x) {
    return lower_bound(hash, hash + hn, x) - hash;
}

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

struct Node {
    int l, r, len, lazy;
    void gao() {
    lazy = 1;
    len = 0;
    }
} node[N * 8];

void pushup(int x) {
    node[x].len = node[lson(x)].len + node[rson(x)].len;
}

void pushdown(int x) {
    if (node[x].lazy) {
    node[x].lazy = 0;
    node[lson(x)].gao();
    node[rson(x)].gao();
    }
}

void build(int l, int r, int x = 0) {
    node[x].l = l; node[x].r = r; node[x].lazy = 0;
    if (l == r) {
    node[x].len = hash[r + 1] - hash[l];
    return;
    }
    int mid = (l + r) / 2;
    build(l , mid, lson(x));
    build(mid + 1, r, rson(x));
    pushup(x);
}

void add(int l, int r, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) {
    node[x].gao();
    return;
    }
    pushdown(x);
    int mid = (node[x].l + node[x].r) / 2;
    if (l <= mid) add(l, r, lson(x));
    if (r > mid) add(l, r, rson(x));
    pushup(x);
}

int query(int l, int r, int x = 0) {
    if (node[x].l >= l && node[x].r <= r)
    return node[x].len;
    int mid = (node[x].l + node[x].r) / 2;
    int ans = 0;
    pushdown(x);
    if (l <= mid) ans += query(l, r, lson(x));
    if (r > mid) ans += query(l, r, rson(x));
    pushup(x);
    return ans;
}

int main() {
    scanf("%d", &n);
    hn = 0;
    for (int i = 0; i < n; i++) {
    scanf("%d%d", &s[i].l, &s[i].r);
    s[i].r += s[i].l;
    hash[hn++] = s[i].l;
    hash[hn++] = s[i].r;
    }
    sort(hash, hash + hn);
    hn = unique(hash, hash + hn) - hash;
    build(0, hn - 2);
    int qn;
    scanf("%d", &qn);
    for (int i = 0; i < qn; i++) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].l--;
    q[i].r--;
    q[i].l = s[q[i].l].l;
    q[i].r = s[q[i].r].l;
    q[i].id = i;
    }
    sort(q, q + qn, cmp);
    int now = n - 1;
    for (int i = 0; i < qn; i++) {
    while (s[now].l >= q[i].l && now >= 0) {
        add(find(s[now].l), find(s[now].r) - 1);
        now--;
    }
    ans[q[i].id] = query(find(q[i].l), find(q[i].r) - 1);
    }
    for (int i = 0; i < qn; i++)
    printf("%d\n", ans[i]);
    return 0;
}