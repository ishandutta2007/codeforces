#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 305;
int n, m, p;

int dp[N][N];

vector<int> r[N];
vector<pair<int, int> > g[N * N];

int dis(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void gao(int x, int y) {
    for (int i = 1; i <= n; i++) {
        int v = lower_bound(r[i].begin(), r[i].end(), y) - r[i].begin();
        if (v - 1 >= 0) {
            dp[i][r[i][v - 1]] = min(dp[i][r[i][v - 1]], dp[x][y] + dis(x, y, i, r[i][v - 1]));
        }
        if (v < r[i].size()) {
            dp[i][r[i][v]] = min(dp[i][r[i][v]], dp[x][y] + dis(x, y, i, r[i][v]));
        }
    }
}

int main() {
    int ex, ey;
    scanf("%d%d%d", &n, &m, &p);
    int x, s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = INF;
            scanf("%d", &x);
            g[x].push_back(make_pair(i, j));
            if (x == 1) {
                dp[i][j] = dis(1, 1, i, j);
            }
            if (x == p) {
                ex = i;
                ey = j;
            }
        }
    }
    for (int i = 1; i < p; i++) {
        for (int j = 1; j <= n; j++) r[j].clear();
        for (int j = 0; j < g[i + 1].size(); j++) {
            int x = g[i + 1][j].first;
            int y = g[i + 1][j].second;
            r[x].push_back(y);
        }
        for (int j = 0; j < g[i].size(); j++) {
            int x = g[i][j].first;
            int y = g[i][j].second;
            if (dp[x][y] == INF) continue;
            gao(x, y);
        }
    }
    printf("%d\n", dp[ex][ey]);
    return 0;
}