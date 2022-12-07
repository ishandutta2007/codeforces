#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, q;
char str[N];

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

struct Node {
    int l, r, cnt[26], lazy[26], et;
    int sz() {
        return r - l + 1;
    }
} node[N * 4];

void pushup(int x) {
    for (int i = 0; i < 26; i++)
        node[x].cnt[i] = node[lson(x)].cnt[i] + node[rson(x)].cnt[i];
}

void pushdown(int x) {
    if (node[x].et) {
        memset(node[lson(x)].lazy, 0, sizeof(node[lson(x)].lazy));
        memset(node[rson(x)].lazy, 0, sizeof(node[rson(x)].lazy));
        node[lson(x)].et = 1;
        node[rson(x)].et = 1;
        memset(node[lson(x)].cnt, 0, sizeof(node[lson(x)].cnt));
        memset(node[rson(x)].cnt, 0, sizeof(node[rson(x)].cnt));
        node[x].et = 0;
    }

    for (int i = 0; i < 26; i++) {
        if (!node[x].lazy[i]) continue;
        node[lson(x)].cnt[i] += node[lson(x)].sz();
        node[rson(x)].cnt[i] += node[rson(x)].sz();
        node[lson(x)].lazy[i] = 1;
        node[rson(x)].lazy[i] = 1;
        node[x].lazy[i] = 0;
    }

}

int cnt[26];

void build(int l, int r, int x = 0) {
    node[x].l = l;
    node[x].r = r;
    if (l == r) {
        node[x].cnt[str[l] - 'a'] = 1;
        return;
    }
    int mid = (l + r)>>1;
    build(l, mid, lson(x));
    build(mid + 1, r, rson(x));
    pushup(x);
}


void get(int l, int r, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) {
        for (int i = 0; i < 26; i++) cnt[i] += node[x].cnt[i];
        return;
    }
    int mid = (node[x].l + node[x].r)>>1;
    pushdown(x);
    if (l <= mid) get(l, r, lson(x));
    if (r > mid) get(l, r, rson(x));
    pushup(x);
}

void empt(int l, int r, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) {

        node[x].et = 1;
        memset(node[x].cnt, 0, sizeof(node[x].cnt));
        memset(node[x].lazy, 0, sizeof(node[x].lazy));
        return;
    }
    int mid = (node[x].l + node[x].r)>>1;
    pushdown(x);
    if (l <= mid) empt(l, r, lson(x));
    if (r > mid) empt(l, r, rson(x));
    pushup(x);
}

void add(int l, int r, int v, int x = 0) {
    if (l > r)return;

    if (node[x].l >= l && node[x].r <= r) {

        node[x].lazy[v] = 1;
        node[x].cnt[v] += node[x].sz();
        return;
    }
    int mid = (node[x].l + node[x].r)>>1;
    pushdown(x);
    if (l <= mid) add(l, r, v, lson(x));
    if (r > mid) add(l, r, v, rson(x));
    pushup(x);
}

char gao(int v, int x = 0) {
    if (node[x].l == node[x].r) {
        for (int i = 0; i < 26; i++) if (node[x].cnt[i]) return i + 'a';
    }
    int mid = (node[x].l + node[x].r)>>1;
    pushdown(x);
    if (v <= mid) return gao(v, lson(x));
    else return gao(v, rson(x));
    pushup(x);
}

int main() {
    scanf("%d%d", &n, &q);
    scanf("%s", str + 1);
    build(1, n);
    int l, r, tp;
    while (q--) {
        scanf("%d%d%d", &l, &r, &tp);
        memset(cnt, 0, sizeof(cnt));
        get(l, r);
        empt(l, r);

        if (!tp) {
            for (int i = 25; i >= 0; i--) {
                if (!cnt[i]) continue;

                add(l, l + cnt[i] - 1, i);
                l += cnt[i];
            }
        } else {
            for (int i = 0; i <= 25; i++) {
                if (!cnt[i]) continue;

                add(l, l + cnt[i] - 1, i);
                l += cnt[i];
            }
        }

    }
    for (int i = 1; i <= n; i++) printf("%c", gao(i));
    printf("\n");
    return 0;
}