#include <bits/stdc++.h>
using namespace std;

vector<string> v;
vector<vector<pair<int, int>>> visited;

void dfs(int x, int y, int dir_x, int dir_y, int c, int k) {
    if (x >= 0 && x < visited.size() && y >= 0 && y < visited[0].size()) {
        if (v[x][y] == '*') return;

        if (k == 0)
            visited[x][y].first = true;
        else
            visited[x][y].second = true;

        // make a turn
        if (c == 0) {
            dfs(x + dir_y, y - dir_x, dir_y, -dir_x, 1, k);
            dfs(x - dir_y, y + dir_x, -dir_y, dir_x, 1, k);
        }

        // same direction
        x += dir_x;
        y += dir_y;
        dfs(x, y, dir_x, dir_y, c, k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    visited.assign(n, vector<pair<int, int>>(m, {false, false}));

    // find s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'S' || v[i][j] == 'T') {
                int k = v[i][j] == 'S';
                dfs(i, j,  1, 0, k, k);
                dfs(i, j, -1, 0, k, k);
                dfs(i, j, 0, -1, k, k);
                dfs(i, j, 0,  1, k, k);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j].first && visited[i][j].second) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}