#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int h, w;
char g[105][105];
int v[105][105];

int res = 0;

int main() {
    scanf("%d%d", &h, &w);
    FO(y,0,h) scanf(" %s", g[y]);
    for (int y = h-1; y >= 0; y--) {
        for (int x = w-1; x >= 0; x--) {
            v[y][x] = v[y][x+1]+v[y+1][x]-v[y+1][x+1];
            int tv = g[y][x] == 'W' ? -1 : 1;
            if (v[y][x] != tv) {
                v[y][x] = tv;
                res++;
            }
        }
    }
    printf("%d\n", res);
}