#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 300005;
const double pi = acos(-1.0);
int n, m;

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

struct Node {
    int l, r;
    int lazy;
    double x, y;
    void gao(int f) {
        lazy = (lazy + f) % 360;
        double r = f * 1.0 / 180 * pi;
        double xx = x * cos(r) + y * sin(r);
        double yy = -x * sin(r) + y * cos(r);
        x = xx;
        y = yy;
    }
} node[N * 4];

void pushup(int x) {
    node[x].x = node[lson(x)].x + node[rson(x)].x;
    node[x].y = node[lson(x)].y + node[rson(x)].y;
}

void pushdown(int x) {
    if (node[x].lazy) {
        node[lson(x)].gao(node[x].lazy);
        node[rson(x)].gao(node[x].lazy);
        node[x].lazy = 0;
    }
}

void build(int l, int r, int x = 0) {
    node[x].l = l; node[x].r = r; node[x].lazy = 0;
    if (l == r) {
        node[x].x = 1.0;
        node[x].y = 0;
        return;
    }
    int mid = (l + r)>>1;
    build(l, mid, lson(x));
    build(mid + 1, r, rson(x));
    pushup(x);
}

void add(int v, int val, int x = 0) {
    if (node[x].l == node[x].r) {
        double tmp = val * 1.0 / sqrt(node[x].x * node[x].x + node[x].y * node[x].y);
        node[x].x *= (1 + tmp);
        node[x].y *= (1 + tmp);
        return;
    }
    int mid = (node[x].l + node[x].r)>>1;
    pushdown(x);
    if (v <= mid) add(v, val, lson(x));
    else add(v, val, rson(x));
    pushup(x);
}

void rot(int l, int r, int val, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) {
        node[x].gao(val);
        return;
    }
    int mid = (node[x].l + node[x].r)>>1;
    pushdown(x);
    if (l <= mid) rot(l, r, val, lson(x));
    if (r > mid) rot(l, r, val, rson(x));
    pushup(x);
}

int main() {
    scanf("%d%d", &n, &m);
    int x, y, z;
    build(1, n);
    while (m--) {
        scanf("%d%d%d", &x, &y, &z);
        if (x == 1) add(y, z);
        else rot(y, n, z);
        printf("%.15f %.15f\n", node[0].x, node[0].y);
    }
    return 0;
}