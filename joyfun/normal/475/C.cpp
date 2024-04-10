#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define sum(x1,y1,x2,y2) (g[x2][y2] - g[x1 - 1][y2] - g[x2][y1 - 1] + g[x1 - 1][y1 - 1])

const int INF = 0x3f3f3f3f;

const int N = 1005;
int n, m, g[N][N], ans = INF;
char str[N][N];

int dfs(int x,int y,int wx,int wy) {
    if(sum(x, y + 1, x + wx - 1, y + wy) == wx * wy) return wx + dfs(x, y + 1, wx, wy);
    if(sum(x + 1, y, x + wx, y + wy - 1) == wx * wy) return wy + dfs(x + 1, y, wx, wy);
    return 0;
}

int main() {
    scanf("%d%d",&n,&m);
    int flag = 0,px,py;
    for(int i = 1; i <= n; i++) scanf("%s",str[i] + 1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(str[i][j] == 'X') {
                if(!flag) {flag = 1; px = i; py = j;}
                g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1] + 1;
            }
            else g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    int tmp,wx,wy;
    for(tmp = px; str[tmp][py] == 'X'; tmp++);
    wx = tmp - px;
    for(int i = py; str[px][i] == 'X'; i++)
        if(dfs(px, py, wx, i - py + 1) + wx * (i - py + 1) == g[n][m])
            ans = min(ans, wx * (i - py + 1));
    for(tmp = py; str[px][tmp] == 'X'; tmp++);
    wy = tmp - py;
    for(int i = px; str[i][py] == 'X'; i++)
        if(dfs(px, py, i - px + 1, wy) + (i - px + 1) * wy == g[n][m]) 
            ans = min(ans, (i - px + 1) * wy);
    if (ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0;
}