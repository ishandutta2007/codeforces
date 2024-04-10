#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 5;
const int S = 32 + 5;
const int INF = 1 << 30;

int n, k, q, K;
int tmp[S], mx[N << 2][S];

void set_node(int rt) {
    for(int i = 0; i < k; i ++)
        scanf("%d", &tmp[i]);
    for(int s = 0; s <= K; s ++) {
        mx[rt][s] = 0;
        for(int i = 0; i < k; i ++)
            mx[rt][s] += (s >> i & 1) ? tmp[i] : - tmp[i];
    }
} 

void upd(int rt) {
    for(int s = 0; s <= K; s ++)
        mx[rt][s] = max(mx[rt << 1][s], mx[rt << 1 | 1][s]);
}

void build(int rt, int l, int r) {
    if(l == r) {
        set_node(rt); 
        return ;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    upd(rt);
}

void modify(int rt, int l, int r, int p) {
    if(l == r) {
        set_node(rt);
        return ;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) modify(rt << 1, l, mid, p);
    else modify(rt << 1 | 1, mid + 1, r, p);
    upd(rt);
}

void query(int rt, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        for(int s = 0; s <= K; s ++)
            tmp[s] = max(tmp[s], mx[rt][s]);
        return ;
    }
    int mid = (l + r) >> 1;
    if(L <= mid) query(rt << 1, l, mid, L, R);
    if(mid < R) query(rt << 1 | 1, mid + 1, r, L, R);
}

int main() {
    scanf("%d%d", &n, &k);
    K = (1 << k) - 1;
    build(1, 1, n);
    scanf("%d", &q);
    int opt, x, y;
    for(int i = 1; i <= q; i ++) {
        scanf("%d%d", &opt, &x);
        if(opt == 1) modify(1, 1, n, x);
        if(opt == 2) {
            scanf("%d", &y);
            fill(tmp, tmp + K + 1, - INF);
            query(1, 1, n, x, y);
            int ans = - INF;
            for(int s = 0; s <= K; s ++)
                ans = max(ans, tmp[s] + tmp[K ^ s]);
            printf("%d\n", ans);
        }
    }
    return 0;
}