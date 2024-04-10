#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    // find start
    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    
    string commands;
    cin >> commands;
    int cnt = 0;
    vector<int> perm = {0, 1, 2, 3};
    do {
        int x = sx;
        int y = sy;
        for (char c : commands) {
            int dir = perm[c - '0'];
            if (dir == 0) {
                x--;
            } else if (dir == 1) {
                x++;
            } else if (dir == 2) {
                y--;
            } else if (dir == 3) {
                y++;
            }

            if (x < 0 || x >= n || y < 0 || y >= m)
                break;
            if (maze[x][y] == '#')
                break;
            if (maze[x][y] == 'E') {
                cnt++;
                break;
            }
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << cnt << '\n';
    
}