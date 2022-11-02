#include <bits/stdc++.h>

const int N = 300007, inf = 0x3f3f3f3f;

int n, ans, S, T;
int es[N], enx[N], ev[N], e0[N], e1[N], h[N], q[N], ep = 2;

int min(int a, int b) { return a < b ? a : b; }

bool bfs() {
    int ql = 0, qr = 0;
    memset(h, 0, sizeof(int) * (T + 2));
    h[q[++qr] = S] = 1;
    while (ql != qr) {
        int w = q[++ql];
        e1[w] = e0[w];
        if (w == T) return 1;
        for (int i = e0[w]; i; i = enx[i])
            if (ev[i]) {
                int u = es[i];
                if (!h[u]) h[q[++qr] = u] = h[w] + 1;
            }
    }
    return 0;
}

int dfs(int w, int f) {
    if (w == T) return f;
    int c, used = 0;
    for (int& i = e1[w]; i; i = enx[i])
        if (ev[i]) {
            int u = es[i];
            if (h[u] != h[w] + 1) continue;
            c = dfs(u, min(f - used, ev[i]));
            if (!c) continue;
            ev[i] -= c;
            ev[i ^ 1] += c;
            used += c;
            if (f == used) return f;
        }
    h[w] = 0;
    return used;
}

void ae(int a, int b, int c) {
    es[ep] = b;
    enx[ep] = e0[a];
    ev[ep] = c;
    e0[a] = ep++;
    es[ep] = a;
    enx[ep] = e0[b];
    ev[ep] = 0;
    e0[b] = ep++;
}

int k;

bool np[200007] = {1, 1};

struct pos {
    int p, c, l;
} ps[107];

int main() {
    for (int i = 2; i <= 200000; ++i)
        if (!np[i])
            for (int j = i * 2; j <= 200000; j += i) np[j] = 1;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &ps[i].p, &ps[i].c, &ps[i].l);
    }
    int L = 1, R = n + 1, M;
    S = n + 1, T = n + 2;
    while (L < R) {
        M = L + R >> 1;
        memset(e0, 0, sizeof(int) * (T + 2));
        ep = 2;
        int m1 = -1, w1 = -1;
        for (int i = 1; i <= n; ++i)
            if (ps[i].l <= M) {
                if (ps[i].c == 1 && ps[i].p > m1) m1 = ps[i].p, w1 = i;
            }
        ans = 0;
        for (int i = 1; i <= n; ++i)
            if (ps[i].l <= M) {
                if (ps[i].c == 1 && i != w1) continue;
                ans += ps[i].p;
                if (ps[i].c & 1) {
                    ae(S, i, ps[i].p);
                    for (int j = 1; j <= n; ++j)
                        if (ps[j].l <= M && (~ps[j].c & 1) &&
                            !np[ps[i].c + ps[j].c]) {
                            ae(i, j, inf);
                        }
                } else
                    ae(i, T, ps[i].p);
            }
        while (bfs()) ans -= dfs(S, inf);
        if (ans < k)
            L = M + 1;
        else
            R = M;
    }
    printf("%d", L > n ? -1 : L);
    return 0;
}