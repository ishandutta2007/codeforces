#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;

typedef long long ll;
int n, a[N], p[N], vis[N], fa[N];
ll ans[N], Max, sum[N];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void gao(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) {
        fa[pu] = pv;
        sum[pv] += sum[pu];
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        fa[i] = i;
        sum[i] = a[i];
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    Max = 0;
    for (int ii = n; ii >= 1; ii--) {
        int i = p[ii];
        ans[ii] = Max;
        if (vis[i + 1]) gao(i, i + 1);
        if (vis[i - 1]) gao(i, i - 1);
        Max = max(Max, sum[find(i)]);
        vis[i] = 1;
    }
    for(int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
    return 0;
}