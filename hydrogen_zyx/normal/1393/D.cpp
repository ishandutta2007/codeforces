#include <bits/stdc++.h>
using namespace std;
int n, m;
char g[2005][2005];
int d[2005][2005];
int vis[2005][2005];
int dir[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
struct node {
    int x, y;
    node() {}
    node(int a, int b) : x(a), y(b) {}
};
queue<pair<int, node> > que;
queue<pair<int, int> > que2;

void bfs(int x, int y) {
    que2.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    while (!que2.empty()) {
        pair<int, int> p = que2.front();
        que2.pop();
        bool edge = 0;
        for (int k = 0; k < 4; k++) {
            int xx = p.first + dir[k][0];
            int yy = p.second + dir[k][1];
            if (xx < 1 || yy < 1 || n < xx || m < yy || g[xx][yy] != g[x][y]) {
                edge = 1;
                continue;
            }
            if (vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            que2.push(pair<int, int>(xx, yy));
        }
        if (edge) {
            que.push(pair<int, node>(1, node(p.first, p.second)));
            d[p.first][p.second] = 1;
        }
    }
}

int main() {
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                bfs(i, j);
                while (!que.empty()) {
                    node e = que.front().second;
                    int dis = que.front().first;
                    que.pop();
                    for (int ii = 0; ii < 4; ii++) {
                        int xx = e.x + dir[ii][0];
                        int yy = e.y + dir[ii][1];
                        if (xx < 1 || yy < 1 || n < xx || m < yy ||
                            g[xx][yy] != g[i][j] || d[xx][yy]) {
                            continue;
                        }
                        d[xx][yy] = dis + 1;
                        que.push(pair<int, node>(dis + 1, node(xx, yy)));
                    }
                }
            }
            ans += d[i][j];
        }
    }
    cout << ans;
}