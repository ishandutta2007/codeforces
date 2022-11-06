#include <bits/stdc++.h>

using namespace std;

void update(int x, int y, int d, const vector<string> &a, vector< vector<int> > &dist) {
    int n = a.size(), m = a[0].size();
    for (int i = 1; ; ++i) {
        int nx = x + i, ny = y;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
        if (a[nx][ny] == '*') break;
        dist[nx][ny] = min(dist[nx][ny], d + 1);
    }
    for (int i = 1; ; ++i) {
        int nx = x - i, ny = y;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
        if (a[nx][ny] == '*') break;
        dist[nx][ny] = min(dist[nx][ny], d + 1);
    }
    for (int i = 1; ; ++i) {
        int nx = x, ny = y + i;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
        if (a[nx][ny] == '*') break;
        dist[nx][ny] = min(dist[nx][ny], d + 1);
    }
    for (int i = 1; ; ++i) {
        int nx = x, ny = y - i;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
        if (a[nx][ny] == '*') break;
        dist[nx][ny] = min(dist[nx][ny], d + 1);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    int stx, sty, finx, finy;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'S') {
                stx = i, sty = j;
            }
            if (a[i][j] == 'T') {
                finx = i, finy = j;
            }
        }
    }
    vector< vector<int> > dist(n, vector<int>(m, 10));
    dist[stx][sty] = 0;
    for (int d = 0; d <= 2; ++d) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dist[i][j] != d) continue;
                if (d == 2 && (i != finx && j != finy)) continue;
                update(i, j, d, a, dist);
            }
        }
    }

    if (dist[finx][finy] == 10) cout << "NO\n";
    else cout << "YES\n";
}