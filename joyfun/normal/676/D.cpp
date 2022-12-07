#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1005;

const int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
const int to[4] = {2, 3, 0, 1};
//up, right, down, left;

int n, m;
char str[N][N];

struct Point {
    int x, y, s;
    Point() {}
    Point(int x, int y, int s) : x(x), y(y), s(s) {}
    void read() {
        scanf("%d%d", &x, &y);
    }
} s, e;

queue<Point> Q;
int vis[4], tmp[4];

void get(char c) {
    for (int i = 0; i < 4; i++) tmp[i] = 1;
    if (c == '+') return;
    if (c == 'L') {tmp[3] = 0; return;}
    if (c == 'R') {tmp[1] = 0; return;}
    if (c == 'U') {tmp[0] = 0; return;}
    if (c == 'D') {tmp[2] = 0; return;}
    memset(tmp, 0, sizeof(tmp));
    if (c == '*') return;
    if (c == '<') {tmp[3] = 1; return;}
    if (c == '^') {tmp[0] = 1; return;}
    if (c == '>') {tmp[1] = 1; return;}
    if (c == 'v') {tmp[2] = 1; return;}
    if (c == '-') {tmp[1] = tmp[3] = 1; return;}
    if (c == '|') {tmp[2] = tmp[0] = 1; return;}
}

void get(char c, int s) {
    get(c);
    for (int i = 0; i < 4; i++)
        vis[(i + s) % 4] = tmp[i];
}

const int INF = 0x3f3f3f3f;

int dp[N][N][4];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", str[i] + 1);
    s.read(); e.read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++)
                dp[i][j][k] = INF;
        }
    }
    Q.push(Point(s.x, s.y, 0));
    dp[s.x][s.y][0] = 0;
    Point u;
    int ff = 0;
    while (!Q.empty()) {
        u = Q.front(); Q.pop();
        if (u.x == e.x && u.y == e.y) {
            ff = 1;
            break;
        }
        get(str[u.x][u.y], u.s);
        int sb[4];
        for (int i = 0; i < 4; i++) sb[i] = vis[i];
        for (int i = 0; i < 4; i++) {
            if (sb[i]) {
                int xx = u.x + dir[i][0];
                int yy = u.y + dir[i][1];
                if (xx <= 0 || xx > n || yy <= 0 || yy > m || dp[xx][yy][u.s] != INF) continue;
                get(str[xx][yy], u.s);
                if (vis[to[i]]) {
                    dp[xx][yy][u.s] = dp[u.x][u.y][u.s] + 1;
                    Q.push(Point(xx, yy, u.s));
                }
            }
        }
        if (dp[u.x][u.y][(u.s + 1) % 4] == INF) {
            dp[u.x][u.y][(u.s + 1) % 4] = dp[u.x][u.y][u.s] + 1;
            Q.push(Point(u.x, u.y, (u.s + 1) % 4));
        }
    }
    if (ff == 0) printf("-1\n");
    else printf("%d\n", dp[u.x][u.y][u.s]);
    return 0;
}