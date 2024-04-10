#include <bits/stdc++.h>
using namespace std;

#prag\
ma GCC optimize(3)
const int maxn = 24, P = 1e9 + 7;
int n, m, flg[3], f[1 << maxn], dis[1 << maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", dis + (1 << i));
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", flg + i);
    }
    f[0] = 1;
    for (int S = 1; S < 1 << n; S++) {
        dis[S] = dis[S ^ (S & -S)] + dis[S & -S];
        if (dis[S] == flg[1] || dis[S] == flg[2]) continue;
        for (int sub = S; sub; sub &= sub - 1) {
            (f[S] += f[S ^ (sub & -sub)]) >= P && (f[S] -= P);
        }
    }
    printf("%d", f[(1 << n) - 1]);
    return 0;
}