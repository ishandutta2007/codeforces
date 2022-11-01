#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char g[505][505];
vector<int> qu[505][505];
int x[600005][2], y[600005][2], ans[600005];
int h, w, q;

int by[505][505];
int sx[505][505];
int bx[505][505];

int main() {
    scanf("%d%d", &h, &w);
    FO(y,0,h) scanf(" %s", g[y]);
    for (int y = h-1; y >= 0; y--) {
        for (int x = w-1; x >= 0; x--) {
            if (g[y][x] == '#') by[y][x] = -100;
            else if (y == h-1) by[y][x] = y;
            else if (x == w-1) by[y][x] = max(y,by[y+1][x]);
            else by[y][x] = max(y,max(by[y+1][x],by[y][x+1]));
        }
    }
    scanf("%d", &q);
    FO(i,0,q) {
        FO(j,0,2) scanf("%d %d", y[i]+j, x[i]+j), y[i][j]--, x[i][j]--;
        if (y[i][1] > by[y[i][0]][x[i][0]]) ans[i] = 1;
        else {
            qu[y[i][0]][x[i][0]].push_back(i);
        }
    }
    FO(yy,0,h) {
        FO(y,yy,h) FO(x,0,w) {
            sx[y][x] = 1e8; bx[y][x] = -1e8;
            if (g[y][x] != '#') {
                if (y == yy) sx[y][x] = bx[y][x] = x;
                else sx[y][x] = min(sx[y][x], sx[y-1][x]), 
                    bx[y][x] = max(bx[y][x], bx[y-1][x]);
                if (x) sx[y][x] = min(sx[y][x], sx[y][x-1]), 
                    bx[y][x] = max(bx[y][x], bx[y][x-1]);
            }
        }
        FO(xx,0,w) for (int i : qu[yy][xx]) {
            int Y = y[i][1], X = x[i][1];
            if (sx[Y][X] <= xx && xx <= bx[Y][X]) ans[i] = 2;
            else ans[i] = 1;
        }
    }
    FO(i,0,q) {
        if (ans[i] == 1) printf("No\n");
        else printf("Yes\n");
    }
}