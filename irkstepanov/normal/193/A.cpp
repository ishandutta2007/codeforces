#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

const int inf = 1e9;

int main()
{

    //ifstream cin("input.txt");

    int n, m;
    cin >> n >> m;

    vector<vector<char> > a(n, vector<char>(m));
    int xmin = inf, xmax = -inf, ymin, ymax;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                ++cnt;
                if (xmin > i) {
                    xmin = i;
                    ymin = j;
                }
                if (xmax <= i) {
                    xmax = i;
                    ymax = j;
                }
            }
        }
    }

    if (cnt <= 2) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#') {
                a[i][j] = '.';
                vector<vector<char> > used(n, vector<char>(m, false));
                queue<int> x, y;
                if (i != xmin || j != ymin) {
                    x.push(xmin);
                    y.push(ymin);
                    used[xmin][ymin] = true;
                } else {
                    x.push(xmax);
                    y.push(ymax);
                    used[xmax][ymax] = true;
                }
                int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
                while (!x.empty()) {
                    int xx = x.front();
                    int yy = y.front();
                    x.pop(), y.pop();
                    for (int step = 0; step < 4; ++step) {
                        int newx = xx + dx[step], newy = yy + dy[step];
                        if (newx >= 0 && newx < n && newy >= 0 && newy < m && a[newx][newy] == '#' && !used[newx][newy]) {
                            x.push(newx);
                            y.push(newy);
                            used[newx][newy] = true;
                        }
                    }
                }
                bool ok = true;
                for (int xx = 0; xx < n; ++xx) {
                    for (int yy = 0; yy < m; ++yy) {
                        if (a[xx][yy] == '#' && !used[xx][yy]) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) {
                        break;
                    }
                }
                a[i][j] = '#';
                if (!ok) {
                    cout << "1\n";
                    return 0;
                }
            }
        }
    }

    cout << "2\n";

}