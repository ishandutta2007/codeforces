#include <bits/stdc++.h>

using namespace std;

const int N = 23;

int n, cs, as;
int ans[N], cur[N];
int a[N][N];

void brute(int p) {
    if (cs >= as) return;
    if (p == n) {
        bool ok = true;
        for (int i = 0; i < n; ++i) ok &= (a[p][i] == (1 << n) - 1);
        if (!ok) return;
        as = cs;
        for (int i = 0; i < as; ++i) ans[i] = cur[i];
        return;
    }
    for (int i = 0; i < n; ++i) {
        a[p + 1][i] = a[p][i];
    }
    brute(p + 1);
    for (int i = 0; i < n; ++i) {
        if (((a[p][p] >> i) & 1) == 0) continue;
        a[p + 1][i] |= a[p + 1][p];
    }
    cur[cs++] = p, brute(p + 1), --cs;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    while (m--) {
        int v, u;
        scanf("%d %d", &v, &u), --v, --u;
        a[0][v] |= 1 << u, a[0][u] |= 1 << v;
    }
    for (int v = 0; v < n; ++v) a[0][v] |= 1 << v;
    as = n + 1, brute(0);
    printf("%d\n", as);
    for (int i = 0; i < as; ++i) printf("%d ", ans[i] + 1);
    printf("\n");
    return 0;
}