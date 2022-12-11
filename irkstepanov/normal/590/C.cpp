#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> pii;

const int inf = 1e7;

int n, m;
vector<vector<char> > a;
vector<vector<int> > dist[3];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int del[3];

void conn(int u, int v)
{
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] - '0' == u && a[i][j] - '0' == v) {
                    ok = true;
                }
            }
        }
    }
    if (ok) {
        //cout << u << " " << v << "\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] - '0' == max(u, v)) {
                    a[i][j] = (char)(min(u, v) + '0');
                }
            }
        }
        del[max(u, v) - 1] = 1;
    }
}

void bfs(int d)
{
    queue<pii> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] - '1' == d) {
                q.push(mp(i, j));
                dist[d][i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int xx = x + dx[k], yy = y + dy[k];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != '#' && dist[d][xx][yy] > dist[d][x][y] + 1) {
                dist[d][xx][yy] = dist[d][x][y] + 1;
                q.push(mp(xx, yy));
            }
        }
    }
}

int main()
{
    
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    
    conn(1, 2);
    conn(1, 3);
    conn(2, 3);
    conn(1, 2);
    conn(1, 3);
    conn(2, 3);
    conn(1, 2);
    conn(1, 3);
    conn(2, 3);
    
    if (del[0] + del[1] + del[2] == 2) {
        cout << "0\n";
        return 0;
    }
    
    for (int i = 0; i < 3; ++i) if (!del[i]) {
        dist[i].resize(n);
        for (int j = 0; j < n; ++j) {
            dist[i][j].assign(m, inf);
        }
    }
    
    for (int i = 0; i < 3; ++i) if (!del[i]) {
        bfs(i);
    }
    
    int ans = inf;
    if (del[0] + del[1] + del[2] == 0) {
        for (int k = 0; k < 3; ++k) {
            int p[3] = {inf, inf, inf};
            p[k] = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] - '1' == k) {
                        for (int d = 0; d < 3; ++d) {
                            if (d != k) p[d] = min(p[d], dist[d][i][j] - 1);
                        }
                    }
                }
            }
            ans = min(ans, p[0] + p[1] + p[2]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != '#') {
                int t = 1;
                for (int k = 0; k < 3; ++k) if (!del[k]) t += dist[k][i][j] - 1;
                ans = min(ans, t);
            }
        }
    }
    
    cout << (ans >= n * m ? -1 : ans) << "\n";

}