#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, int>> neighbours(int i, int j, int n, int m) {
    vector<tuple<int, int>> points;
    if (i - 1 >= 0) points.push_back(make_tuple(i - 1, j));
    if (j - 1 >= 0) points.push_back(make_tuple(i, j - 1));
    if (i + 1 < n) points.push_back(make_tuple(i + 1, j));
    if (j + 1 < m) points.push_back(make_tuple(i, j + 1));
    return points;
}

bool visitable[100][100];
bool tried[100][100];

void visit(vector<vector<char>>& maze, int i, int j, int n, int m) {
    if (tried[i][j]) return;
    visitable[i][j] = true;
    tried[i][j] = true;
    if (i > 0 && maze[i - 1][j] != '#') visit(maze, i - 1, j, n, m);
    if (j > 0 && maze[i][j - 1] != '#') visit(maze, i, j - 1, n, m);
    if (i < n - 1 && maze[i + 1][j] != '#') visit(maze, i + 1, j, n, m);
    if (j < m - 1 && maze[i][j + 1] != '#') visit(maze, i, j + 1, n, m);
}

int main(void) {
    int t;
    cin >> t;
LABEL:    
    while (t--) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                visitable[i][j] = false;
                tried[i][j] = false;
            }
        }
        int n, m; cin >> n >> m;
        vector<vector<char>> maze(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                maze[i].push_back(c);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'B') {
                    auto neighs = neighbours(i, j, n, m);
                    for (auto ne : neighs) {
                        int x = get<0>(ne), y = get<1>(ne);
                        if (maze[x][y] == 'G') {
                            cout << "No\n";
                            goto LABEL;
                        } else if (maze[x][y] != 'B') {
                            maze[x][y] = '#';
                        }
                    }
                }
            }
        }

        // cout << "std\n";

        if (maze[n - 1][m - 1] != '#') visit(maze, n - 1, m - 1, n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'G' && !visitable[i][j]) {
                    cout << "No\n";
                    goto LABEL;
                }
                if (maze[i][j] == 'B' && visitable[i][j]) {
                    cout << "No\n";
                    goto LABEL;
                }
            }
        }

        cout << "Yes\n";

    }
}