#include <bits/stdc++.h>
using namespace std;
constexpr int N = 200000;
constexpr int dx[] = {0, 0, -1, 1, -1, -1, 1, 1}, dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 2);
    for (int i = 0; i < n + 2; ++i)
        a[i].resize(m + 2);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            if (c == 'X')
                a[i][j] = 1;
        }
    }
    vector<vector<int>> dis(n + 2);
    for (int i = 0; i < n + 2; ++i)
        dis[i].assign(m + 2, -1);
    queue<pair<int, int>> que;
    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < m + 2; ++j) {
            if (a[i][j] == 0) {
                que.emplace(i, j);
                dis[i][j] = 0;
            }
        }
    }
    while (!que.empty()) {
        int x, y;
        tie(x, y) = que.front();
        que.pop();
        for (int i = 0; i < 8; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 0 || tx >= n + 2 || ty < 0 || ty >= m + 2 || dis[tx][ty] != -1)
                continue;
            dis[tx][ty] = dis[x][y] + 1;
            que.emplace(tx, ty);
        }
    }
    int t = n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 0)
                continue;
            int k = j;
            while (a[i][k + 1] == 1)
                ++k;
            t = min(t, k - j + 1);
            j = k;
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[j][i] == 0)
                continue;
            int k = j;
            while (a[k + 1][i] == 1)
                ++k;
            t = min(t, k - j + 1);
            j = k;
        }
    }
    t = (t - 1) / 2;
    cout << t << "\n";
    for (int i = 1; i <= n; ++i, cout << "\n")
        for (int j = 1; j <= m; ++j)
            cout << ".X"[dis[i][j] > t];
    return 0;
}