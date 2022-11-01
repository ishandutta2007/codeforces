#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int n;
int t[50];

bool s[305][305][30][8][5];
bool s2[305][305];
int ans = 0;

void go(int x, int y, int i, int d, int rt) {
    if (i == n || s[x][y][i][d][rt]) return;
    s[x][y][i][d][rt] = true;
    if (!s2[x][y]) ans++;
    s2[x][y] = true;
    if (rt+1 == t[i]) {
        int l = (d+7)&7;
        go(x+dx[l], y+dy[l], i+1, l, 0);
        l = (d+1)&7;
        go(x+dx[l], y+dy[l], i+1, l, 0);
    } else go(x+dx[d], y+dy[d], i, d, rt+1);
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", t+i);
    go(151,151,0,0,0);
    printf("%d\n", ans);
}