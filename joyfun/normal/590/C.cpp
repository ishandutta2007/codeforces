#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1005;
const int INF = 0x3f3f3f3f;
const int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

int n, m;
char str[N][N];
int have[5];
int dist[5][5];

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

queue<Point> Q;
int d[4][N][N];
int vis[N][N];

int build(int s, int t, int d[][N]) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d[i][j] = INF;
            if (s == str[i][j] - '0') {
                Q.push(Point(i, j));
                vis[i][j] = 1;
                d[i][j] = 0;
            }
        }
    }
    while (!Q.empty()) {
        Point x = Q.front(); Q.pop();
        vis[x.x][x.y] = 0;
        for (int i = 0; i < 4; i++) {
            Point v = x;
            v.x += dir[i][0];
            v.y += dir[i][1];
            if (v.x < 0 || v.x >= n || v.y < 0 || v.y >= m || str[v.x][v.y] == '#') continue;
            if (d[v.x][v.y] > d[x.x][x.y] + 1) {
                d[v.x][v.y] = d[x.x][x.y] + 1;
                if (!vis[v.x][v.y]) {
                    vis[v.x][v.y] = 1;
                    Q.push(v);
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (t == str[i][j] - '0') {
                ans = min(ans, d[i][j]);
            }
        }
    }
    if (ans == INF) return ans;
    return ans - 1;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
        for (int j = 0; j < m; j++) {
            if (str[i][j] >= '1' && str[i][j] <= '3') have[str[i][j] - '0'] = 1;
        }
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = i + 1; j <= 3; j++) {
            if (have[i] && have[j]) {
                dist[i][j] = dist[j][i] = build(i, j, d[i]);
            }
        }
        if (have[i]) build(i, i, d[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= 3; i++) cnt += have[i];
    int ans = INF;
    if (cnt <= 1) {
        ans = 0;
    } else if (cnt == 2) {
        for (int i = 1; i <= 3; i++) {
            for (int j = i + 1; j <= 3; j++) {
                if (have[i] && have[j]) {
                    ans = min(ans, dist[i][j]);
                }
            }
        }
    } else if (cnt == 3) {
        ans = min(ans, dist[1][2] + dist[2][3]);
        ans = min(ans, dist[1][3] + dist[1][2]);
        ans = min(ans, dist[1][3] + dist[2][3]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 1;
            int flag = 1;
            for (int k = 1; k <= 3; k++) {
                if (have[k]) {
                    if (d[k][i][j] == INF) {
                        flag = 0;
                        break;
                    }
                    sum += d[k][i][j] - 1;
                }
            }
            if (flag) ans = min(ans, sum);
        }
    }
    if (ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0;
}