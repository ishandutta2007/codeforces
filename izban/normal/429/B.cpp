#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
int a[maxn][maxn];

bool ok(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

int dp[maxn][maxn][8];

void bfs(int sx, int sy, int k1, int k2, int n1, int n2) {
    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) dp[i][j][n1] = dp[i][j][n2] = -1;
    dp[sx][sy][n1] = dp[sx][sy][n2] = 0;
    q.push(make_pair(sx, sy));
    
    int k[2]; k[0] = k1; k[1] = k2;
    int N[2]; N[0] = n1; N[1] = n2;
    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        int cd = max(dp[cx][cy][n1], dp[cx][cy][n2]);
        if (cd == -1) {
            assert(0);
        }
        q.pop();
        for (int o = 0; o < 2; o++) {
            int nx = cx + dx[k[o]], ny = cy + dy[k[o]];
            if (!ok(nx, ny)) continue;
            if (dp[nx][ny][n1] == -1 && dp[nx][ny][n2] == -1) {
                q.push(make_pair(nx, ny));
            }
            dp[nx][ny][N[o]] = cd + a[cx][cy];
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    
    bfs(0, 0, 0, 2, 0, 1);
    bfs(n - 1, 0, 1, 2, 2, 3);
    bfs(0, m - 1, 0, 3, 4, 5);
    bfs(n - 1, m - 1, 1, 3, 6, 7);
    
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            ans = max(ans, dp[i][j][0] + dp[i][j][6] + dp[i][j][3] + dp[i][j][5]);
            ans = max(ans, dp[i][j][1] + dp[i][j][7] + dp[i][j][4] + dp[i][j][2]);
        }
    }
    
    cout << ans << endl;

	return 0;
}