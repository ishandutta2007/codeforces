#include <cstdio>
#include <cstring>
#include <vector>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int h, w, m;
int g[1005][1005];
int lr[1005][1005];
int rres[1005];

int tv[1005];

int ZZ;

void mod(int &y, int &x) {
    if (ZZ & 1) {
        swap(y,x);
    }
    if (ZZ&2) {
        x = w-x-1;
    }
}

void clr(int y) {
    for (int x = 0; x < w; x++) {
        if (g[y][x] == 0) lr[y][x] = 0;
        else if (x == 0) lr[y][x] = 1;
        else lr[y][x] = lr[y][x-1] + 1;
    }
}

int main() {
    for (ZZ = 0; ZZ < 4; ZZ++) {
        rewind(stdin);
        scanf("%d %d %d", &h, &w, &m);
        int H=h,W=w;
        if (ZZ&1) swap(h,w);
        FO(y,0,H) FO(x,0,W) {
            int Y=y,X=x;
            mod(Y,X);
            scanf(" %d", &g[Y][X]);
        }
        FO(y,0,h) clr(y);
        FO(Z,0,m) {
            int T, y, x;
            scanf("%d", &T);
            scanf("%d %d", &y, &x); y--; x--; mod(y,x);
            if (T == 1) {
                g[y][x] = !g[y][x];
                clr(y);
            } else {
                int res = 0;

                FO(yy,y,h) {
                    tv[yy] = lr[yy][x];
                    if (yy != y && tv[yy-1] < tv[yy]) tv[yy] = tv[yy-1];
                    res = max(res, tv[yy] * (yy-y+1));
                }
                for (int yy = y-1; yy >= 0; yy--) {
                    tv[yy] = lr[yy][x];
                    if (yy != y-1 && tv[yy+1] < tv[yy]) tv[yy] = tv[yy+1];
                }

                /*FO(yy,0,h) {
                  printf("%d\n", tv[yy]);
                  }
                  printf("--\n");*/

                int lp = y-1, rp = y;
                while (lp >= 0 && rp < h) {
                    res = max(res, min(tv[lp],tv[rp]) * (rp-lp+1));
                    if (lp == 0) {
                        if (rp == h-1) break;
                        rp++;
                    } else if (rp == h-1) {
                        lp--;
                    } else if (min(tv[lp-1],tv[rp]) <= min(tv[lp],tv[rp+1])) {
                        rp++;
                    } else {
                        lp--;
                    }
                }
                //printf("%d: %d\n", Z, res);
                rres[Z] = max(rres[Z], res);
                if (ZZ == 3) printf("%d\n", rres[Z]);
            }
        }
    }
}