#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
const int N = 1000005;

int n, k;
int v[N], c[N], p[N];

double f[N];

double C(int n, int m) {
    return f[n] - f[m] - f[n - m];
}

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

struct Node {
    int Max, Min;
} node[N * 4];

void pushup(int x) {
    node[x].Max = max(node[lson(x)].Max, node[rson(x)].Max);
    node[x].Min = min(node[lson(x)].Min, node[rson(x)].Min);
}

void build(int l, int r, int x = 0) {
    if (l == r) {
        node[x].Max = v[l];
        node[x].Min = c[l];
        return;
    }
    int mid = (l + r)>>1;
    build(l, mid, lson(x));
    build(mid + 1, r, rson(x));
    pushup(x);
}

int Max1, Min1;

void rmq(int l, int r, int L = 1, int R = n, int x = 0) {
    if (L >= l && R <= r) {
        Max1 = max(Max1, node[x].Max);
        Min1 = min(Min1, node[x].Min);
        return;
    }
    int mid = (L + R)>>1;
    if (l <= mid) rmq(l, r, L, mid, lson(x));
    if (r > mid) rmq(l, r, mid + 1, R, rson(x));
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    //build(1, n);
    p[n] = min(v[n] * 100, c[n]);
    int pre = n;
   /* for (int i = n - 1; i >= 1; i--) {
        while (pre > i) {
            Max1 = 0, Min1 = 1000000000;
            rmq(i, pre - 1);
            int Max2 = max(Max1, v[pre]);
            int Min2 = min(Min1, c[pre]);
           // printf("%d %d %lld %lld %lld %lld\n", i, pre, Max1, Min1, Max2, Min2);
            if (min(Max1 * 100, Min1) >= min(Max2 * 100, Min2))
                pre--;
            else break;
        }
        Max1 = 0, Min1 = 1000000000;
        rmq(i, pre);
        p[i] = min(Max1 * 100, Min1);
    }*/
    int Max = v[n], Min = c[n];
    for (int i = n - 1; i >= 1; i--) {
        Max = max(Max, v[i]); Min = min(Min, c[i]);
        if (min(Max * 100, Min) <= min(v[i] * 100, c[i]))
            Max = v[i], Min = c[i];
        p[i] = min(Max * 100, Min);
    }
    //for (int i = 1; i <= n; i++) printf("%lld ", p[i]);
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + log(i * 1.0);
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        if (k - 1 > n - i) break;
        ans += exp(log(p[i] * 1.0) + C(n - i, k - 1) - C(n, k));
    }
    printf("%.12f\n", ans);
    return 0;
}