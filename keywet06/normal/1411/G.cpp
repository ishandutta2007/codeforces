#include <bits/stdc++.h>

const int N = 1 << 18;
const int M = 998244353;
const int F2 = (M + 1) / 2;

using int64 = long long;

int power(int x, int y) {
    int ans = 1;
    for (; y; y >>= 1, x = (int64)x * x % M) {
        if (y & 1) ans = (int64)ans * x % M;
    }
    return ans;
}

struct Edge {
    int v, nxt;
} e[N << 1];
int n, head[N], cnt;
inline void addedge(int u, int v) { e[++cnt] = (Edge){v, head[u]}, head[u] = cnt; }

int sg[N], buc[N];
int dfs(int x) {
    if (~sg[x]) return sg[x];
    sg[x] = 0;
    if (!head[x]) return sg[x];
    for (int i = head[x]; i; i = e[i].nxt) dfs(e[i].v);
    for (int i = head[x]; i; i = e[i].nxt) buc[sg[e[i].v]] = 1;
    for (int &i = sg[x]; buc[i]; ++i)
        ;
    for (int i = head[x]; i; i = e[i].nxt) buc[sg[e[i].v]] = 0;
    return sg[x];
}

int f[N], g[N], h[N];

int XOR[2][2] = {1, 1, 1, M - 1}, IXOR[2][2] = {F2, F2, F2, M - F2};
void fwt(int *a, int lim, int T[2][2]) {
    const int n = 1 << lim;
    for (int m = 1, k = 2; m < n; m <<= 1, k <<= 1)
        for (int j = 0; j < n; j += k)
            for (int i = j; i < (j | m); ++i) {
                int64 x = a[i], y = a[i | m];
                a[i] = (x * T[0][0] + y * T[0][1]) % M;
                a[i | m] = (x * T[1][0] + y * T[1][1]) % M;
            }
}
int limit(int n) {
    int ans = 0;
    for (int i = 1; i < n; i <<= 1, ++ans)
        ;
    return ans;
}

int main() {
    int m, u, v;
    for (scanf("%d %d", &n, &m); m; --m) scanf("%d %d", &u, &v), addedge(u, v);
    memset(sg, -1, sizeof(sg));
    for (int i = 1; i <= n; ++i) dfs(i);
    for (int i = 1; i <= n; ++i) g[sg[i]]++;
    int lim = limit(n), sup = 1 << lim;
    for (int i = 1; i < sup; ++i) h[i] = 1;
    fwt(g, lim, XOR), fwt(h, lim, XOR);
    for (int i = 0; i < sup; ++i) f[i] = (int64)h[i] * power(n + 1 + M - g[i], M - 2) % M;
    fwt(f, lim, IXOR);
    printf("%d\n", f[0]);
    return 0;
}