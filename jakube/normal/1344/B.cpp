#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<string> board;
int n, m;

void bfs(int start_x, int start_y, int comp) {
    std::queue<std::pair<int, int>> q;

    q.push({start_x, start_y});
    v[start_x][start_y] = comp;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        int dx = 0, dy = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == '#' && v[nx][ny] == -1) {
                v[nx][ny] = comp;
                q.push({nx, ny});
            }
            int tmp = dx;
            dx = -dy;
            dy = tmp;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    board.resize(n);
    for (auto& x : board)
        cin >> x;
    
    v.assign(n, vector<int>(m, -1));
    // find components
    int components = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '#' && v[i][j] == -1) {
                bfs(i, j, components++);
            }
        }
    }

    bool possible = true;
    for (int i = 0; i < n; i++) {
        char last = '.';
        bool already_seen_one = false;
        for (int j = 0; j < m; j++) {
            char cur = board[i][j];
            if (!already_seen_one) {
                if (cur == '#')
                    already_seen_one = true;
            } else {
                if (cur == '#' && last == '.')
                    possible = false;
            }
            last = cur;
        }
    }
    for (int j = 0; j < m; j++) {
        char last = '.';
        bool already_seen_one = false;
        for (int i = 0; i < n; i++) {
            char cur = board[i][j];
            if (!already_seen_one) {
                if (cur == '#')
                    already_seen_one = true;
            } else {
                if (cur == '#' && last == '.')
                    possible = false;
            }
            last = cur;
        }
    }

    bool empty_rows = false;
    for (int i = 0; i < n; i++) {
        bool empty = true;
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '#')
                empty = false;
        }
        if (empty)
            empty_rows = true;
    }
    bool empty_cols = false;
    for (int j = 0; j < m; j++) {
        bool empty = true;
        for (int i = 0; i < n; i++) {
            if (board[i][j] == '#')
                empty = false;
        }
        if (empty)
            empty_cols = true;
    }

    if ((empty_cols || empty_rows) && !(empty_rows && empty_cols))
        possible = false;

    if (possible)
        cout << components << '\n';
    else
        cout << -1 << '\n';
}