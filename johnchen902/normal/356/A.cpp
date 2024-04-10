#include <cstdio>
using namespace std;

static struct {
    bool has_val;
    int val;
} seg[(1 << 20) - 1];
static_assert(1 << 19 >= 300000, "too small");

void init() {
    seg[0].has_val = true;
}

void modify(int l, int r, int x, int nl = 0, int nr = (1 << 19), int k = 0) {
    if(l <= nl && nr <= r) {
        seg[k].has_val = true;
        seg[k].val = x;
    } else if(!(r <= nl || nr <= l)) {
        if(seg[k].has_val) {
            seg[k].has_val = false;
            seg[2 * k + 1].has_val = true;
            seg[2 * k + 1].val = seg[k].val;
            seg[2 * k + 2].has_val = true;
            seg[2 * k + 2].val = seg[k].val;
        }
        modify(l, r, x, nl, (nl + nr) / 2, 2 * k + 1);
        modify(l, r, x, (nl + nr) / 2, nr, 2 * k + 2);
    }
}

int query(int i, int nl = 0, int nr = (1 << 19), int k = 0) {
    if(seg[k].has_val)
        return seg[k].val;
    else if(i < (nl + nr) / 2)
        return query(i, nl, (nl + nr) / 2, 2 * k + 1);
    else
        return query(i, (nl + nr) / 2, nr, 2 * k + 2);
}

int l[300000], r[300000], x[300000];

int main(){
    init();
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
        scanf("%d %d %d", l + i, r + i, x + i);
    for(int i = m - 1; i >= 0; i--) {
        modify(l[i] - 1, x[i] - 1, x[i]);
        modify(x[i], r[i], x[i]);
    }
    for(int i = 0; i < n; i++)
        printf("%d%c", query(i), i==n-1?'\n':' ');
}