#include <bits/stdc++.h>

using namespace std;

const int C = 20;
const int N = 100005;

int n, q, ta, tb, tc, td, te, tv, rt = 1;
int x[N], ia[N], ib[N], h[N];
int par[N][C];

long long y[C][N], z[C][N];

vector<int> va[N], vb[N], vc[N];

inline int f(int a, int b) { return (1 << (a)) * (b); }

void dfs(int a, int b, int c) {
    par[a][0] = b;
    h[a] = c;
    for (int i = 1; i < C; i++) par[a][i] = par[par[a][i - 1]][i - 1];
    y[0][ta] = x[a];
    ia[a] = ta++;
    c++;
    for (int i = 0; i < va[a].size(); i++)
        if (va[a][i] != b) {
            vb[a].push_back(va[a][i]);
            vc[a].push_back(ta);
            dfs(va[a][i], a, c);
        }
    ib[a] = ta;
}

int lca(int a, int b) {
    if (h[a] < h[b]) swap(a, b);
    int tt = h[a] - h[b];
    for (int i = 17; i >= 0; i--)
        if (tt & (1 << i)) a = par[a][i];
    if (a == b) return a;
    for (int i = 17; i >= 0; i--)
        if (par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
    return par[a][0];
}

void f1(int a, int b, int c, int d) {
    y[c][d] += (long long)tv * (b - a);
    if (f(c, d) == a && f(c, d + 1) == b) {
        z[c][d] += tv;
        return;
    }
    c--, d = d * 2 + 1;
    if (b <= f(c, d))
        f1(a, b, c, d - 1);
    else if (a >= f(c, d))
        f1(a, b, c, d);
    else
        f1(a, f(c, d), c, d - 1), f1(f(c, d), b, c, d);
}

long long f2(int a, int b, int c, int d) {
    if (f(c, d) == a && f(c, d + 1) == b) return y[c][d];
    long long re = z[c][d] * (b - a);
    c--, d = d * 2 + 1;
    if (a < f(c, d)) re += f2(a, min(b, f(c, d)), c, d - 1);
    if (b > f(c, d)) re += f2(max(a, f(c, d)), b, c, d);
    return re;
}

void add(int a, int b) {
    tv = tc;
    if (b == 0)
        f1(ia[a], ib[a], 17, 0);
    else if (a == b) {
        y[17][0] += (long long)tc * n;
        z[17][0] += tc;
    } else {
        int tt =
            upper_bound(vc[a].begin(), vc[a].end(), ia[b]) - vc[a].begin() - 1;

        y[17][0] += (long long)tc * n;
        z[17][0] += tc;

        tv = -tc;
        f1(ia[vb[a][tt]], ib[vb[a][tt]], 17, 0);
    }
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", x + i);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &ta, &tb);
        va[ta].push_back(tb);
        va[tb].push_back(ta);
    }
    ta = 0;
    dfs(1, 0, 0);
    for (int i = 1; i < C; i++)
        for (int j = 0; f(i, j) < n; j++)
            y[i][j] = y[i - 1][j * 2] + y[i - 1][j * 2 + 1];

    while (q--) {
        scanf("%d%d", &ta, &tb);
        if (ta == 1)
            rt = tb;
        else if (ta == 2) {
            scanf("%d%d", &ta, &tc);
            td = lca(ta, tb);
            te = lca(td, rt);
            if (h[te] < h[td])
                add(td, 0);
            else {
                te = lca(ta, rt);

                if (h[te] > h[td])
                    add(te, rt);
                else {
                    te = lca(tb, rt);
                    if (h[te] > h[td])
                        add(te, rt);
                    else
                        add(td, rt);
                }
            }

        } else {
            tc = lca(tb, rt);

            if (h[tc] < h[tb])
                printf("%lld\n", f2(ia[tb], ib[tb], 17, 0));
            else if (tb == rt)
                printf("%lld\n", y[17][0]);
            else {
                int tt = upper_bound(vc[tb].begin(), vc[tb].end(), ia[rt]) -
                         vc[tb].begin() - 1;
                printf("%lld\n",
                       y[17][0] - f2(ia[vb[tb][tt]], ib[vb[tb][tt]], 17, 0));
            }
        }
    }
    return 0;
}