#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

using namespace std;

int h, w;

int yv[505], xv[505];

int bsm = 1e9, by0 = -1;

int main() {
    scanf("%d %d", &h, &w);
    int g[105][105];
    fo(y,0,h) fo(x,0,w) {
        scanf("%d ", &g[y][x]);
    }
    fo(y0,0,505) {
        yv[0] = y0;
        fo(x,0,w) xv[x] = g[0][x] - yv[0];
        fo(y,1,h) yv[y] = g[y][0] - xv[0];

        bool bad= false;
        int sm = 0;
        fo(x,0,w) fo(y,0,h) if (xv[x] < 0 || yv[y] < 0 ||
                xv[x] + yv[y] != g[y][x]) {
            bad = true;
        }
        fo(x,0,w) sm += xv[x];
        fo(y,0,h) sm += yv[y];
        if (!bad) {
            if (sm < bsm) {
                by0 = y0;
                bsm = sm;
            }
        }
    }
    if (bsm > 1e8) bsm = -1;
    printf("%d\n", bsm);
    if (bsm != -1) {
        yv[0] = by0;
        fo(x,0,w) xv[x] = g[0][x] - yv[0];
        fo(y,1,h) yv[y] = g[y][0] - xv[0];

        fo(y,0,h) fo (_,0,yv[y]) printf("row %d\n", y+1);
        fo(x,0,w) fo (_,0,xv[x]) printf("col %d\n", x+1);
    }
}