#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 150005;

int n, m, c;
long long xx[N], p[N];

#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)

struct Sum {
    long long l, r, w, sum;
    Sum() {}
    Sum(long long x) {
        l = r = w = max(0LL, x);
        sum = x;
    }
};

Sum meg(Sum a, Sum b) {
    Sum ans;
    ans.w = max(max(a.w, b.w), a.r + b.l);
    ans.l = max(a.l, a.sum + b.l); ans.r = max(b.r, b.sum + a.r);
    ans.sum = (a.sum + b.sum);
    return ans;
}
struct Node {
    Sum s;
} node[N<<2];

void pushup(int x) {
    node[x].s = meg(node[lson(x)].s, node[rson(x)].s);
}

void build(int L, int R, int x = 1) {
    if (L == R) {
        node[x].s = Sum(xx[L]);
        return;
    }
    int mid = (L + R)>>1;
    build(L, mid, lson(x));
    build(mid + 1, R, rson(x));
    pushup(x);
  //  printf("%d %d %lld!!\n", L, R, node[x].s.w);
}

Sum get(int l, int r, int L, int R, int x = 1) {
    if (L >= l && R <= r) return node[x].s;
    int mid = (L + R)>>1;
    if (l <= mid && r > mid) return meg(get(l, r, L, mid, lson(x)), get(l, r, mid + 1, R, rson(x)));
    else if (l <= mid) return get(l, r, L, mid, lson(x));
    else if (r > mid) return get(l, r, mid + 1, R, rson(x));
}

int main() {
    scanf("%d%d%d", &n, &m, &c);
    for (int i = 1; i <= n; i++) scanf("%lld", &xx[i]);
    for (int i = 1; i <= n - 1; i++) scanf("%d", &p[i]);
    for (int i = 1; i < n; i++) {
        xx[i] = (xx[i + 1] - xx[i] - c * 2) * p[i] + (xx[i + 1] - xx[i]) * (100 - p[i]);
       // printf("%d %lld\n", i, xx[i]);
    }
    build(1, n - 1);
    int l, r;
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        //printf("%lld!!\n", get(l, r - 1, 1, n - 1).w);
        ans += get(l, r - 1, 1, n - 1).w;
    }
    printf("%.12f\n", ans / 200.0);
    return 0;
}