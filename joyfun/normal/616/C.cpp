#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
using namespace std;

const int N = 1005;
const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int n, m;
char g[N][N];
int vis[N][N];
int cnt[N][N];

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

queue<Point> Q;
stack<Point> S;
int id[N][N];

void bfs(int x, int y) {
    int cntt = 0;
    Q.push(Point(x, y));
    vis[x][y] = 1;
    while (!Q.empty()) {
        Point u = Q.front(); Q.pop();
        S.push(u);
        cntt++;
        for (int i = 0; i < 4; i++){
            int x = u.x + dir[i][0];
            int y = u.y + dir[i][1];
            if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || g[x][y] == '*') continue;
            vis[x][y] = true;
            Q.push(Point(x, y));
        }
    }
    while (!S.empty()) {
        Point u = S.top(); S.pop();
        cnt[u.x][u.y] = cntt;
        id[u.x][u.y] = x * m + y;
    }
}

char ans[N][N];
set<int> use;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", &g[i]);
    for (int i =0 ; i< n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && g[i][j] == '.')
                bfs(i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') ans[i][j] = '.';
            else {
                int tmp = 1;
                use.clear();
                for (int k = 0; k < 4; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '*') continue;
                    if (use.find(id[x][y]) != use.end()) continue;
                    use.insert(id[x][y]);
                    tmp = (tmp + cnt[x][y]) % 10;
                }
                ans[i][j] = tmp + '0';
            }
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}