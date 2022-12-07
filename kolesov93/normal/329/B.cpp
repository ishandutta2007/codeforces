#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acosl(-1.);
using namespace std;

const int N = 1111;
char w[N][N];
int d[N][N];

int n, m;
int sx, sy, tx, ty;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    scanf("%d%d\n", &n, &m);
    memset(w, 'T', sizeof(w));
    for (int i = 1; i <= n; ++i) {
        gets(w[i] + 1);
        w[i][m + 1] = 'T';
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (w[i][j] == 'E') {
                tx = i;
                ty = j;
            } else if (w[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }

    queue<pair<int, int> > q;
    memset(d, 63, sizeof(d));
    q.push(make_pair(tx, ty));
    d[tx][ty] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    while (!q.empty()) {
        pair<int, int> t = q.front(); q.pop();
        
        int x = t.first, y = t.second;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];

            if (w[nx][ny] != 'T' && d[nx][ny] > d[x][y] + 1) {
                d[nx][ny] = d[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    int ans = 0;
    int lim = d[sx][sy];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (w[i][j] >= '0' && w[i][j] <= '9' && d[i][j] <= lim)
                ans += w[i][j] - '0';

    cout << ans << endl;

    return 0;
}