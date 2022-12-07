#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 100005;
const int MOD = 1000000007;
const int X = 123;

int n, m, k;
int hx[N];
int rp;

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

struct Node {
    int l, r, sum, lazy;
    int sz() {
        return r - l + 1;
    }
    void gao(int f) {
        lazy = f;
        sum = ((ll)f * (1 - hx[sz()]) % MOD + MOD) % MOD * rp % MOD;
    }
} node[N * 4];

char str[N];

int pow_mod(int x, int k) {
    int ans = 1;
    while (k) {
        if (k&1) ans = (long long)ans * x % MOD;
        x = (long long)x * x % MOD;
        k >>= 1;
    }
    return ans;
}

void pushup(int x) {
    node[x].sum = ((ll)node[lson(x)].sum * hx[node[rson(x)].sz()] % MOD + node[rson(x)].sum) % MOD;
}

void pushdown(int x) {
    if (node[x].lazy != -1) {
        node[lson(x)].gao(node[x].lazy);
        node[rson(x)].gao(node[x].lazy);
        node[x].lazy = -1;
    }
}

void build(int l, int r, int x = 0) {
    node[x].l = l; node[x].r = r;
    node[x].lazy = -1;
    if (l == r) {
        node[x].sum = str[l] - '0';
        return;
    }
    int mid = (l + r)>>1;
    build(l, mid, lson(x));
    build(mid + 1, r, rson(x));
    pushup(x);
}

void modify(int l, int r, int c, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) {
        node[x].gao(c);
        return;
    }
    int mid = (node[x].l + node[x].r)>>1;
    pushdown(x);
    if (l <= mid) modify(l, r, c, lson(x));
    if (r > mid) modify(l, r, c, rson(x));
    pushup(x);
}

int ans;

void query(int l, int r, int x = 0) {
    if (node[x].l >= l && node[x].r <= r) {
        ans = ((ll)ans * hx[node[x].sz()] % MOD + node[x].sum) % MOD;
        return;
    }
    int mid = (node[x].l + node[x].r)>>1;
    pushdown(x);
    if (l <= mid) query(l, r, lson(x));
    if (r > mid) query(l ,r, rson(x));
    pushup(x);
}

int main() {
    rp = pow_mod(MOD - 122, MOD - 2);
    hx[0] = 1;
    for (int i = 1; i < N; i++) hx[i] = (long long)hx[i - 1] * X % MOD;
    scanf("%d%d%d", &n, &m, &k);
    m += k;
    scanf("%s", str + 1);
    build(1, n);
    int tp, l, r, c;
    while (m--) {
        scanf("%d%d%d%d", &tp, &l, &r, &c);
        if (tp == 1) {
            modify(l, r, c);
        } else if (tp == 2) {
            if (c == r - l + 1) {
                printf("YES\n");
                continue;
            }
            ans = 0; query(l + c, r);
            int s1 = ans;
            ans = 0; query(l, r - c);
          //  printf("%d %d\n", ans, s1);
            printf("%s\n", s1 == ans ? "YES" : "NO");
        }
    }
    return 0;
}