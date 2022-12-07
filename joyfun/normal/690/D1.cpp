#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;

const int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int r, c;
char str[N][N];
int vis[N][N];

void dfs(int x, int y) {
    if (vis[x][y]) return;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0 || xx >= r || yy < 0 || yy >= c || str[xx][yy] == '.' || vis[xx][yy]) continue;
        dfs(xx, yy);
    }
}

int main() {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) scanf("%s", str[i]);
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!vis[i][j] && str[i][j] == 'B') {
                dfs(i, j);
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}