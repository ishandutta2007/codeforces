#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, k;
    cin >> n >> m >> k;
    
    vector<string> maze(n);
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }
    
    //find pos
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'X')
                x = i, y = j;
        }
    }

    if (k % 2) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<vector<int>> dist(n, vector<int>(m, -2));
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {x, y}});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        auto cord = cur.second;
        dist[cord.first][cord.second] = cur.first;

        vector<vector<int>> tmp = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (auto d : tmp) {
            int X = cord.first + d[0];
            int Y = cord.second + d[1];
            if (X >= 0 && X < n && Y >= 0 && Y < m && maze[X][Y] != '*' && dist[X][Y] == -2) {
                dist[X][Y] = -1;
                q.push({cur.first + 1, {X, Y}});
            }
        }
    }


    vector<char> res;
    for (int i = 0; i < k; i++) {
        if (dist[x][y] < k - i) {
            if (x + 1 < n && maze[x+1][y] != '*') {
                res.push_back('D');
                x++;
            } else if (y - 1 >= 0 && maze[x][y-1] != '*') {
                res.push_back('L');
                y--;
            } else if (y + 1 < m && maze[x][y+1] != '*') {
                res.push_back('R');
                y++;
            } else if (x - 1 >= 0 && maze[x-1][y] != '*') {
                res.push_back('U');
                x--;
            } else {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        } else {
            char best = ' ';
            int be = 1e9;

            if (x + 1 < n && maze[x+1][y] != '*' && dist[x+1][y] < be) {
                be = dist[x+1][y];
                best = 'D';
            }
            if (y - 1 >= 0 && maze[x][y-1] != '*' && dist[x][y-1] < be) {
                be = dist[x][y-1];
                best = 'L';
            }
            if (y + 1 < m && maze[x][y+1] != '*' && dist[x][y+1] < be) {
                be = dist[x][y+1];
                best = 'R';
            }
            if (x - 1 >= 0 && maze[x-1][y] != '*' && dist[x-1][y] < be) {
                be = dist[x-1][y];
                best = 'U';
            }

            res.push_back(best);
            if (best == 'U')
                x--;
            if (best == 'L')
                y--;
            if (best == 'R')
                y++;
            if (best == 'D')
                x++;
        }
    }

    for (auto c : res) 
        cout << c;
    cout << endl;
}