#include <bits/stdc++.h>
using namespace std;
char g[100][100];
int dir[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool vis[100][100];
int n, m;
bool dfs1(int x, int y) {
    if (vis[x][y]) return 1;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx == 0 || yy == 0 || xx > n || yy > m) continue;
        if (g[xx][yy] == '.')
            g[xx][yy] = '#';
        else if (g[xx][yy] == 'G')
            return 0;
        else if (g[xx][yy] == 'B')
            if (!dfs1(xx, yy)) return 0;
    }
    return 1;
}
void dfs2(int x, int y) {
    if (g[x][y] == '0') return;
    g[x][y] = '0';
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx == 0 || yy == 0 || xx > n || yy > m) continue;
        if (g[xx][yy] == '.' || g[xx][yy] == 'G') dfs2(xx, yy);
    }
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        memset(vis, 0, sizeof(vis));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
            }
        }
        int ok = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (g[i][j] == 'B') {
                    if (!dfs1(i, j)) {
                        ok = 1;
                    }
                }
            }
        }
        if (g[n][m] != '#') dfs2(n, m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (g[i][j] == 'G') ok = 1;
            }
        }
        if (ok)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}