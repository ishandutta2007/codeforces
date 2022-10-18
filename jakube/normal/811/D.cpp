#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> pre;
vector<string> v;

bool LRswapped = false;
bool UDswapped = false;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int x = 0, y = 0;
    if (v[0][1] == '*') {
        cout << "D" << endl;
        cin >> x >> y;
        x--, y--;
        if (v[x][y] == 'F') return 0;
        if (x == 0 && y == 0) {
            UDswapped = true;
        }

        while (v[x][y + 1] == '*') {
            cout << (UDswapped ? "U" : "D") << endl;
            cin >> x >> y;
            x--, y--;
            if (v[x][y] == 'F') return 0;
        }
        
        cout << "R" << endl;
        cin >> x >> y;
        x--, y--;
        if (v[x][y] == 'F') return 0;
        if (y == 0) {
            LRswapped = true;
        }
    } else {
        cout << "R" << endl;
        cin >> x >> y;
        x--, y--;
        if (v[x][y] == 'F') return 0;
        if (y == 0) {
            LRswapped = true;
        } else {
            cout << "L" << endl;
            cin >> x >> y;
            x--, y--;
            if (v[x][y] == 'F') return 0;
        }

        while (v[x + 1][y] == '*') {
            cout << (LRswapped ? "L" : "R") << endl;
            cin >> x >> y;
            x--, y--;
            if (v[x][y] == 'F') return 0;
        }
        
        cout << "D" << endl;
        cin >> x >> y;
        x--, y--;
        if (v[x][y] == 'F') return 0;
        if (x == 0) {
            UDswapped = true;
        }
    }

    pre.assign(n, vector<int>(m, -1));
    pre[x][y] = 1111;
    // right
    stack<pair<int, int>> s;
    s.push({x, y});
    while (!s.empty()) {
        tie(x, y) = s.top();
        s.pop();

        if (y + 1 < m && v[x][y+1] != '*' && pre[x][y+1] == -1) {
            pre[x][y+1] = 0;
            s.push({x, y+1});
        }
        // left
        if (y > 0 && v[x][y-1] != '*' && pre[x][y-1] == -1) {
            pre[x][y-1] = 1;
            s.push({x, y-1});
        }
        // up
        if (x > 0 && v[x-1][y] != '*' && pre[x-1][y] == -1) {
            pre[x-1][y] = 2;
            s.push({x - 1, y});
        }
        // down
        if (x + 1 < n && v[x+1][y] != '*' && pre[x+1][y] == -1) {
            pre[x+1][y] = 3;
            s.push({x + 1, y});
        }
    }

    // find goal
    int goal_x, goal_y;
    for (goal_x = 0; goal_x < n; goal_x++) {
        for (goal_y = 0; goal_y < m; goal_y++) {
            if (v[goal_x][goal_y] == 'F') 
                break;
        }
        if (v[goal_x][goal_y] == 'F') 
            break;
    }

    vector<int> path;
    while (pre[goal_x][goal_y] != 1111) {
        // if (path.size() > 100*100) {
            // return 0;
        // }
        int val = pre[goal_x][goal_y];
        path.push_back(val);
        if (val == 0) {
            goal_y--;
        } else if (val == 1) {
            goal_y++;
        } else 
        if (val == 2)
            goal_x++;
        else
        if (val == 3)
            goal_x--;
        else
            return 0;
    }

    reverse(path.begin(), path.end());
    for (int i : path) {
        if (i == 0) {
            cout << (LRswapped ? "L" : "R") << endl;
        } else if (i == 1) {
            cout << (LRswapped ? "R" : "L") << endl;
        } else if (i == 2) {
            cout << (UDswapped ? "D" : "U") << endl;
        } else 
            cout << (UDswapped ? "U" : "D") << endl;

        cin >> x >> y;
        x--, y--;
        if (v[x][y] == 'F') return 0;
    }
}