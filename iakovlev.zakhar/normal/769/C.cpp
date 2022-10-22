#include <bits/stdc++.h>

using namespace std;

const int INF = (int)(1e9);

int n, m, rest;
int my_x, my_y;

string answer = "";

bool made_turn;

bool make_turn(int dx, int dy, vector< vector<int> > &dist, vector< vector<bool> > &wall) {
    int next_x = my_x + dx, next_y = my_y + dy;
    if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m || wall[next_x][next_y]) {
        return false;
    }
    if (dist[next_x][next_y] > rest) {
        return false;
    }
    //cout << "BEFORE: " << my_x << " " << my_y << "\n";
    my_x = next_x;
    my_y = next_y;
    //cout << "AFTER: " << my_x << " " << my_y << "\n";
    if (dy == -1) answer += "L";
    else if (dy == 1) answer += "R";
    else if (dx == 1) answer += "D";
    else answer += "U";
    --rest;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> rest;
    vector< vector<bool> > wall (n, vector<bool>(m, false));

    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};

    //reading
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            char c = s[j];
            if (c == '.') continue;
            if (c == '*') wall[i][j] = true;
            if (c == 'X') {
                my_x = i;
                my_y = j;
            }
        }
    }

    int start_x = my_x, start_y = my_y;

    //bfs
    vector< vector<int>> dist(n, vector<int>(m, INF));
    queue< pair<int, int> > q;
    dist[my_x][my_y] = 0;
    q.push({my_x, my_y});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int cur_x = p.first, cur_y = p.second;
        for (int mv = 0; mv < 4; ++mv) {
            int x = cur_x + dx[mv], y = cur_y + dy[mv];
            if (x > -1 && y > -1 && x < n && y < m && !wall[x][y] && dist[x][y] == INF) {
                dist[x][y] = dist[cur_x][cur_y] + 1;
                q.push({x, y});
            }
        }
    }

    // generation the answer

    while (rest > 0) {
        made_turn = false;
        for (int mv = 0; mv < 4 && !made_turn; ++mv) {
            bool success = make_turn(dx[mv], dy[mv], dist, wall);
            made_turn |= success;
        }
        if (!made_turn) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    //output

    if (!(start_x == my_x && start_y == my_y)) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << answer << "\n";
    }
}