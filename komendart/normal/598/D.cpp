#include <bits/stdc++.h>

using namespace std;

int n, m, k;
pair<int, int> parent[1000][1000];
int answer[1000][1000];
char used[1000][1000];
string graph[1000];

int dfs(int x, int y, int px, int py) {
    if (used[x][y]) return 0;
    if (graph[x][y] == '*') return 1;
    used[x][y] = true;
    parent[x][y] = {px, py};
    return dfs(x + 1, y, px, py) + dfs(x - 1, y, px, py) +
    dfs(x, y + 1, px, py) + dfs(x, y - 1, px, py);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            answer[i][j] = dfs(i, j, i, j);
        }
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        auto p = parent[x][y];
        cout << answer[p.first][p.second] << '\n';
    }
}