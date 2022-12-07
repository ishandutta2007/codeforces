#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

int n;

struct Line {
    int l, r, y, f;
    Line() {}
    Line(int l, int r, int y, int f) {
        this->l = l;
        this->r = r;
        this->y = y;
        this->f = f;
    }
    bool operator < (const Line& c) const {
        return y < c.y;
    }
} line[N * 2];
int ln;

int H[N * 2], hn;

int find(int x) {
    return lower_bound(H, H + hn, x) - H;
}

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

struct Node {
    int l, r, cnt, sum;
} node[N * 8];

void build(int l, int r, int x = 0) {
    node[x].l = l;
    node[x].r = r;
    node[x].cnt = node[x].sum = 0;
    if (l == r) return;
    int mid = (l + r)>>1;
    build(l, mid, lson(x));
    build(mid + 1, r, rson(x));
}

void pushup(int x) {
    if (node[x].l == node[x].r) {
        if (node[x].cnt) node[x].sum = H[node[x].r + 1] - H[node[x].l];
        else node[x].sum = 0;
    } else {
        if (node[x].cnt) node[x].sum = H[node[x].r + 1] - H[node[x].l];
        else node[x].sum = node[lson(x)].sum + node[rson(x)].sum;
    }
}

void add(int l, int r, int val, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) {
        node[x].cnt += val;
        pushup(x);
        return;
    }
    int mid = (node[x].l + node[x].r)>>1;
    if (l <= mid) add(l, r, val, lson(x));
    if (r > mid) add(l, r, val, rson(x));
    pushup(x);
}

long long solve() {
    scanf("%d", &n);
    int xa, ya, xb, yb;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
        if (xa == xb) if (ya > yb) swap(ya, yb);
        if (ya == yb) if (xa > xb) swap(xa, xb);
        xb++; yb++;
        H[hn++] = xa; H[hn++] = xb;
        line[ln++] = Line(xa, xb, ya, 1);
        line[ln++] = Line(xa, xb, yb, -1);
    }
    sort(H, H + hn);
    hn = unique(H, H + hn) - H;
    build(0, hn - 2);
    sort(line, line + ln);
    long long ans = 0;
    for (int i = 0; i < ln; i++) {
        if (i) ans += 1LL * (line[i].y - line[i - 1].y) * node[0].sum;
        add(find(line[i].l), find(line[i].r) - 1, line[i].f);
    }
    return ans;
}

int main() {
    printf("%lld\n", solve());
    return 0;
}