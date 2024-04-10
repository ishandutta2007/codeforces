#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int g[1005][1005];
int dir[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int n, m;

void bfs(int x, int y) {
    queue<pair<int, int> > que;
    g[x][y] = 3;
    que.push(pair<int, int>(x, y));
    while (!que.empty()) {
        x = que.front().first;
        y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 1 || yy < 1 || xx > n || yy > m || g[xx][yy] != 1)
                continue;
            g[xx][yy] = 3;
            que.push(pair<int, int>(xx, yy));
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '#')
                g[i][j] = 1;
            else
                g[i][j] = 0;
        }
    }
    bool f = 1;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 1 && (g[i][j - 1] == 0 || g[i][j - 1] == 2)) cnt++;
        }
        if (cnt > 1) f = 0;
        if (cnt != 0) {
            for (int j = 1; j <= m; j++)
                if (g[i][j] == 0) g[i][j] = 2;
        }
    }
    for (int i = 1; i <= m; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (g[j][i] == 1 && (g[j - 1][i] == 0 || g[j - 1][i] == 2)) cnt++;
        }
        if (cnt > 1) f = 0;
        if (cnt != 0) {
            for (int j = 1; j <= n; j++)
                if (g[j][i] == 0) g[j][i] = 2;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 1) bfs(i, j), ans++;
        }
    }
    for (int i = 1; i <= n; i++) {
        bool ff = 0;
        for (int j = 1; j <= m; j++)
            if (g[i][j] == 0 || g[i][j] == 3) ff = 1;
        f &= ff;
    }
    for (int i = 1; i <= m; i++) {
        bool ff = 0;
        for (int j = 1; j <= n; j++)
            if (g[j][i] == 0 || g[j][i] == 3) ff = 1;
        f &= ff;
    }
    if (f)
        cout << ans;
    else
        cout << -1;
}