#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;

int n, m, k;
char str[N];

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

struct Node {
    int l, r, cnt[10][10], lv, rv, lazy;
    void gao(int f) {
        lazy = f;
        lv = rv = f;
        memset(cnt, 0, sizeof(cnt));
    }
} node[N * 4];

void pushdown(int x) {
    if (node[x].lazy != -1) {
        node[lson(x)].gao(node[x].lazy);
        node[rson(x)].gao(node[x].lazy);
        node[x].lazy = -1;
    }
}

void pushup(int x) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            node[x].cnt[i][j] = node[lson(x)].cnt[i][j] + node[rson(x)].cnt[i][j];
        }
    }
    node[x].cnt[node[lson(x)].rv][node[rson(x)].lv]++;
    node[x].lv = node[lson(x)].lv;
    node[x].rv = node[rson(x)].rv;
}

void build(int l, int r, int x = 0) {
    node[x].lazy = -1;
    node[x].l = l; node[x].r = r;
    if (l == r) {
        node[x].lv = node[x].rv = str[l] - 'a';
        return;
    }
    int mid = (l + r)>>1;
    build(l, mid, lson(x));
    build(mid + 1, r, rson(x));
    pushup(x);
}

void add(int l, int r, int val, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) {
        node[x].gao(val);
        return;
    }
    int mid = (node[x].l + node[x].r)>>1;
    pushdown(x);
    if (l <= mid) add(l, r, val, lson(x));
    if (r > mid) add(l, r, val, rson(x));
    pushup(x);
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", str + 1);
    build(1, n);
    int tp, l, r;
    while (m--) {
        scanf("%d", &tp);
        if (tp == 1) {
            scanf("%d%d%s", &l, &r, &str);
            add(l, r, str[0] - 'a');
        } else {
            scanf("%s", str);
            int len = strlen(str);
            int ans = n;
            for (int i = 0; i < len; i++)
                for (int j = i + 1; j < len; j++)
                    ans -= node[0].cnt[str[i] - 'a'][str[j] - 'a'];
            printf("%d\n", ans);
        }
    }
    return 0;
}