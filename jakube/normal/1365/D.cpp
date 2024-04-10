#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (auto& row : board)
        for (auto& x : row)
            cin >> x;

    int G = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'G')
                G++;
            if (board[i][j] == 'B') {
                pair<int, int> d = {0, 1};
                for (int k = 0; k < 4; k++) {
                    int x = i + d.first;
                    int y = j + d.second;
                    if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == '.')
                        board[x][y] = '#';
                    d = {-d.second, d.first};
                }
            }
        }
    }

    vector<vector<bool>> found(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, int>> q;

    pair<int, int> start = {n-1, m-1};
    q.push({start, 0});
    found[n-1][m-1] = true;

    int B = 0;

    while (!q.empty()) {
        auto p = q.front();
        auto cur = p.first;
        q.pop();
        if (board[cur.first][cur.second] == 'G')
            G--;
        if (board[cur.first][cur.second] == 'B')
            B++;
        if (board[cur.first][cur.second] == '#')
            continue;
        int dist = p.second;

        pair<int, int> d = {0, 1};
        for (int i = 0; i < 4; i++) {
            int x = cur.first + d.first;
            int y = cur.second + d.second;
            if (x >= 0 && x < n && y >= 0 && y < m && !found[x][y]) {
                q.push({{x, y}, dist + 1});
                found[x][y] = true;
            }
            d = {-d.second, d.first};
        }
    }

    if (G == 0 && B == 0)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        solve();
    }
}