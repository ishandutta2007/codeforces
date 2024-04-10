#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

int nn, mm;

void ispis (int cx, int cy, int ofs, int sign) {
    cx += ofs; cy += ofs;
    if (sign == -1) {
        cx = nn - cx + 1;
        cy = mm - cy + 1;
    }
    printf("%d %d\n", cx, cy);
}

void rjesi (int n, int m, int ofs, int sign) {
    if (n == 0 || m == 0) return;
    if (n >= 2 && m >= 2) {
        int cx = 1, cy = 1;
        ispis(cx, cy, ofs, sign);
        int dx = n-1, dy = m-1;
        while (dy != -(m-1)) {
            cx += dx; cy += dy;
            ispis(cx, cy, ofs, sign);
            if (dx > 0) dy = -(dy-1); else dy = -(dy+1);
            dx = -dx;
        }
        while (1) {
            cx += dx; cy += dy;
            if (cx == n && cy == m) break;
            ispis(cx, cy, ofs, sign);
            if (dy < 0) dx = -(dx-1); else dx = -(dx+1);
            dy = -dy;
        }
        rjesi(n-2, m-2, ofs+1, -sign);
    } else if (n == 1) {
        for (int i=1; i*2<=m; i++) {
            ispis(1, i, ofs, sign);
            int nxt = m - i + 1;
            ispis(1, nxt, ofs, sign);
        }
        if (m & 1) ispis(1, (m+1)/2, ofs, sign);
    } else {
        for (int i=1; i*2<=n; i++) {
            ispis(i, 1, ofs, sign);
            int nxt = n - i + 1;
            ispis(nxt, 1, ofs, sign);
        }
        if (n & 1) ispis((n+1)/2, 1, ofs, sign);
    }
}

int main () {
    scanf("%d%d", &nn, &mm);
    rjesi(nn, mm, 0, 1);
    return 0;
}