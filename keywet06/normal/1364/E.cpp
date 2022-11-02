#include <bits/stdc++.h>
const int N = 2048;
int n, zr_1, zr_2, zr;
int p[N], vl, a[N];
int q(int x, int y) {
    printf("? %d %d\n", x + 1, y + 1);
    fflush(stdout);
    int rt;
    scanf("%d", &rt);
    return rt;
}
bool c(int x) {
    int sb = 2047, tt = 30, rd;
    while (tt--) {
        rd = rand() % n;
        while (rd == x) rd = rand() % n;
        sb &= q(rd, x);
    }
    return (sb == 0);
}
int main() {
    srand(19260817);
    scanf("%d", &n);
    zr_1 = 0;
    zr_2 = 1;
    vl = q(0, 1);
    for (int i = 2; i < n; i++) {
        int nv_1 = q(zr_1, i), nv_2;
        if (nv_1 <= vl) {
            nv_2 = q(zr_2, i);
            if (nv_1 < nv_2) {
                zr_2 = i;
                vl = nv_1;
            }
            if (nv_2 < nv_1) {
                zr_1 = i;
                vl = nv_2;
            }
        }
    }
    if (c(zr_1)) zr = zr_1;
    if (c(zr_2)) zr = zr_2;
    for (int i = 0; i < n; i++)
        if (i != zr) p[i] = q(i, zr);
    printf("! ");
    for (int i = 0; i < n - 1; i++) printf("%d ", p[i]);
    printf("%d\n", p[n - 1]);
    fflush(stdout);
    return 0;
}