#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    // dijkstra
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {x1-1, y1-1}});
    int INF = numeric_limits<int>::max();
    vector<vector<int>> visited(n, vector<int>(m, INF));
    visited[x1-1][y1-1] = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (visited[top.second.first][top.second.second] != -top.first)
            continue;
        if (top.second.first == x2-1 && top.second.second == y2-1) {
            cout << -top.first << endl;
            return 0;
        }

        pair<int, int> dir = {1, 0};
        for (int i = 0; i < 4; i++) {
            bool b = true;
            for (int j = 1; j <= k && b; j++) {
                int x = top.second.first + dir.first * j;
                int y = top.second.second + dir.second * j;

                if (0 <= x && x < n && 0 <= y && y < m) {
                    if (v[x][y] == '#')
                        break;
                    if (visited[x][y] > -top.first + 1) {
                        visited[x][y] = -top.first + 1;
                        pq.push({-visited[x][y], {x, y}});
                    } else if (visited[x][y] <= -top.first)
                        b = false;
                } else {
                    break;
                }
            }


            dir = {dir.second, -dir.first};
        }
        
    }

    cout << -1 << endl;
}