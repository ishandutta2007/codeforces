#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int INF = 1000000007;

int n, m;
vector <string> a;
vector <int> red;
vector < vector <int> > p, r, bio;
queue < pair <int, int> > q;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

inline int get (int x1, int y1, int x2, int y2) {
    return p[x2][y2] - (x1 == 0 ? 0 : p[x1 - 1][y2]) - (y1 == 0 ? 0 : p[x2][y1 - 1]) + (x1 == 0 || y1 == 0 ? 0 : p[x1 - 1][y1 - 1]);
}

void ispis () {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (r[i][j]) cout << 'X'; else cout << '.';
        }
        cout << '\n';
    }
}

bool ok (int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && bio[x][y] == INF;
}

bool moze (int t) {
    int area = (2 * t + 1) * (2 * t + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bio[i][j] = INF;
            if (i - t >= 0 && i + t < n && j - t >= 0 && j + t < m && get(i - t, j - t, i + t, j + t) == area) {
                r[i][j] = 1;
                q.push({i, j});
                bio[i][j] = 0;
            } else {
                r[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (ok(nx, ny)) {
                bio[nx][ny] = bio[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((bio[i][j] <= t) ^ (a[i][j] == 'X')) return 0;
        }
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    red.resize(m);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        a.push_back(s);
        p.push_back(red);
        r.push_back(red);
        bio.push_back(red);
        for (int j = 0; j < m; j++) {
            p[i][j] = (a[i][j] == 'X');
            if (i > 0) p[i][j] += p[i - 1][j];
            if (j > 0) p[i][j] += p[i][j - 1];
            if (i > 0 && j > 0) p[i][j] -= p[i - 1][j - 1];
        }
    }
    int lo = 0, hi = min(n, m);
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (moze(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    moze(lo);
    cout << lo << '\n';
    ispis();
    return 0;
}