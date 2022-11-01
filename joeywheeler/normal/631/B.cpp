#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int h, w, k;
int t[100005], v[100005], a[100005];
int r[5005][5005];
bool yc[5005], xc[5005];

int main() {
    scanf("%d%d %d", &h, &w, &k);
    FO(i,0,k) scanf("%d %d %d", t+i, v+i, a+i);
    for (int i = k; i--; ) {
        if (t[i] == 1) {
            int y = v[i]-1;
            if (yc[y]) continue;
            yc[y] = true;
            FO(x,0,w) if (r[y][x] == 0) r[y][x] = a[i];
        } else {
            int x = v[i]-1;
            if (xc[x]) continue;
            xc[x] = true;
            FO(y,0,h) if (r[y][x] == 0) r[y][x] = a[i];
        }
    }
    FO(y,0,h) FO(x,0,w) printf("%d%c", r[y][x], " \n"[x+1==w]);
}