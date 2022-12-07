#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

const int N = 300005;

int n, v[N], p[N];

struct Node {
    int l, r, Min, lazy, val1, val2;
    void gao(int x) {
        lazy += x;
        Min += x;
    }
} node[N * 4];

void build(int l, int r, int x = 0) {
    node[x].l = l; node[x].r = r;
    node[x].Min = node[x].lazy = node[x].val2 = 0;
    node[x].val1 = r - l + 1;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(l, mid, lson(x));
    build(mid + 1, r, rson(x));
}

void pushdown(int x) {
    if (node[x].lazy) {
       node[lson(x)].gao(node[x].lazy);
       node[rson(x)].gao(node[x].lazy);
    }
    node[x].lazy = 0;
}

void pushup(int x) {
    node[x].Min = min(node[lson(x)].Min, node[rson(x)].Min);
    node[x].val1 = (node[lson(x)].Min == node[x].Min) * node[lson(x)].val1 + (node[rson(x)].Min == node[x].Min) * node[rson(x)].val1;
    node[x].val2 = (node[lson(x)].Min == node[x].Min + 1) * node[lson(x)].val1 + (node[rson(x)].Min == node[x].Min + 1) * node[rson(x)].val1;
    node[x].val2 += (node[lson(x)].Min == node[x].Min) * node[lson(x)].val2 + (node[rson(x)].Min == node[x].Min) * node[rson(x)].val2;
}

void add(int l, int r, int val, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) {
        node[x].gao(val);
        return;
    }
    pushdown(x);
    int mid = (node[x].l + node[x].r) / 2;
    if (l <= mid) add(l, r, val, lson(x));
    if (r > mid) add(l, r, val, rson(x));
    pushup(x);
}

ll ans;

void query(int l, int r, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) {
         if (node[x].Min == 1) {
            ans += node[x].val1 + node[x].val2;
         } else if (node[x].Min == 2)
            ans += node[x].val1;
         return;
    }
    pushdown(x);
    int mid = (node[x].l + node[x].r) / 2;
    if (l <= mid) query(l, r, lson(x));
    if (r > mid) query(l, r, rson(x));
    pushup(x);
}

int main() {
    scanf("%d", &n);
    int tmp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        v[tmp] = i;
    }
    ans = 0;
    build(1, n);
    memset(p, 0, sizeof(p));
    for (int i = n; i >= 1; i--) {
        p[v[i]] = i;
        int x = p[v[i] - 1], y = p[v[i] + 1];
        if (x > y) swap(x, y);
        if (x) {
            add(i, x - 1, 1);
            add(y, n, -1);
        } else if (y) add(i, y - 1, 1);
        else add(i, n, 1);
        query(i, n);
    }
    printf("%I64d\n", ans - n);
    return 0;
}