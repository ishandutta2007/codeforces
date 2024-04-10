#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> pii;

const int inf = 1e9;

int main() 
{
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<char> > a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int x0, y0;
    
    vector<vector<int> > dist(n, vector<int>(m, inf));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'X') {
                x0 = i, y0 = j;
            }
        }
    }
    
    dist[x0][y0] = 0;
    queue<pii> q;
    q.push({x0, y0});
    
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};
    
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != '*' && dist[xx][yy] == inf) {
                dist[xx][yy] = dist[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
    
    if (k & 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    string ans = "";
    
    for (int i = 0; i < k; ++i) {
        bool ok = false;
        for (int j = 0; j < 4; ++j) {
            int x = x0 + dx[j], y = y0 + dy[j];
            if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '*' && dist[x][y] <= k - i - 1) {
                if (j == 0) {
                    ans += "D";
                } else if (j == 1) {
                    ans += "L";
                } else if (j == 2) {
                    ans += "R";
                } else {
                    ans += "U";
                }
                x0 = x, y0 = y;
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "IMPOSSIBLE\n";
          return 0;
        }
    }
    
    cout << ans << "\n";
    
}