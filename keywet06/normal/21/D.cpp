#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;
const int B = 2;
const int C = 15;
const int D = 1 << C | 1;

int n, m;
int par[C], lev[C];
int f[B][D];

int anc(int t) {
    if (par[t] != t) par[t] = anc(par[t]);
    return par[t];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) par[i] = i;
    for (int i = 1; i < (1 << n); ++i) f[0][i] = INF;
    for (int i = 1; i <= m; ++i) {
        int I = i & 1, J = I ^ 1;
        int u, v, r;
        scanf("%d %d %d", &u, &v, &r);
        ++lev[--u], ++lev[--v];
        par[anc(u)] = anc(v);
        for (int j = 0; j < (1 << n); ++j) {
            f[I][j] = min(f[J][j] + 2 * r, f[J][j ^ (1 << u) ^ (1 << v)] + r);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (anc(i) != anc(0) && lev[i] > 0) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", f[m & 1][0]);
    return 0;
}