#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int w, h;
char g[505][505];
int le[505][505];
int up[505][505];

int qsum(int a[505][505], int y1, int x1, int y2, int x2) {
    if (y1 > y2 || x1 > x2) return 0;
    y2++; x2++;
    return a[y2][x2] - a[y2][x1] - a[y1][x2] + a[y1][x1];
}

int main() {
    scanf("%d %d", &h, &w);
    FO(y,0,h) {
        scanf(" %s", g[y]);
    }
    FO(y,0,h) {
        FO(x,1,w) {
            le[y+1][x+1] = g[y][x] == '.' && g[y][x-1] == '.';
        }
    }
    FO(y,1,h) FO(x,0,w) {
        up[y+1][x+1] = g[y][x] == '.' && g[y-1][x] == '.';
    }
    FO(y,1,h+1) FO(x,1,w+1) {
        le[y][x] += le[y-1][x] + le[y][x-1] - le[y-1][x-1];
        up[y][x] += up[y-1][x] + up[y][x-1] - up[y-1][x-1];
    }
    int q; scanf("%d", &q);
    FO(i,0,q) {
        int y1, x1, y2, x2;
        scanf("%d%d%d%d", &y1, &x1, &y2, &x2); y1--; x1--; y2--; x2--;
        printf("%d\n", qsum(le, y1, x1+1, y2, x2) + qsum(up, y1+1, x1, y2, x2));
    }
}