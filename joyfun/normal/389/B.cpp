#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 105;
const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, vis[N][N], ans;
char g[N][N];


bool ju(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    if (g[x][y] == '.') return false;
    for (int i = 0; i < 4; i++) {
        int xx = x + d[i][0];
        int yy = y + d[i][1];
        if (xx < 0 || xx >= n || yy < 0 || yy >= n) return false;
        if (g[xx][yy] == '.' || vis[xx][yy]) return false;
    }
    return true;
}

bool solve() {
    int num = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (ju(i, j)) {
                vis[i][j] = 1;
                num++;
                for (int k = 0; k < 4; k++) {
                    int xx = i + d[k][0];
                    int yy = j + d[k][1];
                    vis[xx][yy] = 1;
                    num++;
                }
            }   
        }
    if (num == ans)
        return true;
    return false;
}

int main() {
    ans = 0;
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", g[i]);
        for (int j = 0; j < n; j++)
            if (g[i][j] == '#') ans++;
    }
    printf("%s\n", solve() ? "YES" : "NO");
    return 0;
}