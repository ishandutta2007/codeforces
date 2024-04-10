#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 205;

int n, m, nodes;
char c[MAXN][MAXN];
bool hor[MAXN][MAXN], ver[MAXN][MAXN];
int dist[MAXN][MAXN];
pi par_u[MAXN][MAXN], par_v[MAXN][MAXN];
vector <pi> v[MAXN][MAXN];
queue <pi> q;

void build () {
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            if (row < n && c[row][col] == '#' && c[row + 1][col] == '#') hor[row][col] = 1, nodes++;
            if (col < m && c[row][col] == '#' && c[row][col + 1] == '#') ver[row][col] = 1, nodes++;
        }
    }
    for (int row = 1; row < n; row++) {
        for (int col = 1; col <= m; col++) {
            if (!hor[row][col]) continue;

            if (ver[row][col]) v[row][col].push_back({row, col});
            if (ver[row + 1][col]) v[row][col].push_back({row + 1, col});
            if (col > 1) {
                if (ver[row][col - 1]) v[row][col].push_back({row, col - 1});
                if (ver[row + 1][col - 1]) v[row][col].push_back({row + 1, col - 1});
            }
        }
    }
}

bool bfs () {
    for (int row = 1; row < n; row++) {
        for (int col = 1; col <= m; col++) {
            if (!hor[row][col]) continue;
            if (par_u[row][col] == make_pair(0, 0)) {
                dist[row][col] = 0;
                q.push({row, col});
            } else {
                dist[row][col] = 1e9;
            }
        }
    }
    dist[0][0] = 1e9;
    while (!q.empty()) {
        int row = q.front().first, col = q.front().second;
        q.pop();
        if (dist[row][col] >= dist[0][0]) continue;
        for (auto pp : v[row][col]) {
            int nr = par_v[pp.first][pp.second].first;
            int nc = par_v[pp.first][pp.second].second;
            if (dist[nr][nc] == 1e9) {
                dist[nr][nc] = 1 + dist[row][col];
                q.push({nr, nc});
            }
        }
    }
    return dist[0][0] < 1e9;
}

bool dfs (int row, int col) {
    if (row == 0 && col == 0) return 1;
    if (dist[row][col] == 1e9) return 0;
    for (auto pp : v[row][col]) {
        int nr = par_v[pp.first][pp.second].first;
        int nc = par_v[pp.first][pp.second].second;
        if (dist[nr][nc] == 1 + dist[row][col] && dfs(nr, nc)) {
            par_u[row][col] = {pp.first, pp.second};
            par_v[pp.first][pp.second] = {row, col};
            return 1;
        }
    }
    dist[row][col] = 1e9;
    return 0;
}

int matching () {
    int res = 0;
    while (bfs()) {
        for (int row = 1; row < n; row++) {
            for (int col = 1; col <= m; col++) {
                if (!hor[row][col]) continue;
                if (dist[row][col] == 0 && dfs(row, col)) res++;
            }
        }
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int br = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if (c[i][j] == '#') br++;
        }
    }
    build();
    cout << br - (nodes - matching());
    return 0;
}