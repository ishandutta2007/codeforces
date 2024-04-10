#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200500
#define ll long long
int n, m, va[N], vb[N], lx, ly;
int lm[N], rm[N];
bool chk(int v1) {
    lm[0] = m;
    for (int i = 1; i <= n; i++) {
        lm[i] = lm[i - 1];
        while (lm[i] && va[i] + vb[lm[i]] > v1) lm[i]--;
    }
    rm[0] = n;
    for (int i = 1; i <= m; i++) {
        rm[i] = rm[i - 1];
        while (rm[i] && vb[i] + va[rm[i]] > v1) rm[i]--;
    }
    ll mx = 0, su = 0;
    for (int i = 1; i <= n; i++) su += m - lm[i];
    // rx++:su+=min(ry,lm[rx])-min(m-ry,m-lm[rx])
    // ry++:su+=min(rx,rm[ry])-min(n-rx,n-rm[ry])
    for (int rx = 0, ry = 0; ry <= m;) {
        while (rx < n && min(ry, lm[rx + 1]) >= min(m - ry, m - lm[rx + 1]))
            rx++, su += min(ry, lm[rx]) - min(m - ry, m - lm[rx]);
        if (mx <= su)
            mx = su;
        ry++;
        su += min(rx, rm[ry]) - min(n - rx, n - rm[ry]);
    }
    su = 0;
    for (int i = 1; i <= n; i++) su += m - lm[i];
    for (int rx = 0, ry = 0; ry <= m;) {
        while (rx < n && min(ry, lm[rx + 1]) >= min(m - ry, m - lm[rx + 1]))
            rx++, su += min(ry, lm[rx]) - min(m - ry, m - lm[rx]);
        if (mx <= su && (rx >= lx || ry >= ly))
            return 1;
        ry++;
        su += min(rx, rm[ry]) - min(n - rx, n - rm[ry]);
    }
    su = 0;
    for (int i = 1; i <= n; i++) su += m - lm[i];
    for (int rx = 0, ry = 0; rx <= n;) {
        while (ry < m && min(rx, rm[ry]) >= min(n - rx, n - rm[ry]))
            ry++, su += min(rx, rm[ry]) - min(n - rx, n - rm[ry]);
        if (mx <= su && (rx >= lx || ry >= ly))
            return 1;
        rx++;
        su += min(ry, lm[rx]) - min(m - ry, m - lm[rx]);
    }
    return 0;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &va[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &vb[i]);
    lx = va[1];
    ly = vb[1];
    sort(va + 1, va + n + 1);
    sort(vb + 1, vb + m + 1);
    for (int i = 1; i <= n; i++)
        if (lx == va[i]) {
            lx = i;
            break;
        }
    for (int i = 1; i <= m; i++)
        if (ly == vb[i]) {
            ly = i;
            break;
        }
    int lb = 0, rb = va[lx] + vb[ly], as = rb;
    while (lb <= rb) {
        int mid = (lb + rb) >> 1;
        if (chk(mid))
            as = mid, rb = mid - 1;
        else
            lb = mid + 1;
    }
    printf("%d\n", as);
}