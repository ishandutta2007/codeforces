#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
int u[405][405];

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,m) {
        int x, y; scanf("%d%d", &x, &y); x--; y--;
        u[x][y] = u[y][x] = 1;
    }
    if (u[0][n-1] == 1) {
        FO(i,0,n) FO(j,0,n) if (i-j) u[i][j] = 1-u[i][j];
    }
    FO(i,0,n) FO(j,0,n) if (i-j && !u[i][j]) u[i][j] = 5000;
    FO(i,0,n) FO(j,0,n) FO(k,0,n) u[j][k] = min(u[j][k], u[j][i] + u[i][k]);
    if (u[0][n-1] < 4000) {
        printf("%d\n", u[0][n-1]);
    } else {
        printf("%d\n", -1);
    }
}