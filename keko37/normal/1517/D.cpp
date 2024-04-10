#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 505;

int n, m, k;
int rig[MAXN][MAXN], dwn[MAXN][MAXN];
int dist[MAXN][MAXN][25];

void upd (int h) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j][h] = 1e9;
            if (i + 1 < n) dist[i][j][h] = min(dist[i][j][h], dwn[i][j] + dist[i + 1][j][h - 1]);
            if (i - 1 >= 0) dist[i][j][h] = min(dist[i][j][h], dwn[i - 1][j] + dist[i - 1][j][h - 1]);
            if (j + 1 < m) dist[i][j][h] = min(dist[i][j][h], rig[i][j] + dist[i][j + 1][h - 1]);
            if (j - 1 >= 0) dist[i][j][h] = min(dist[i][j][h], rig[i][j - 1] + dist[i][j - 1][h - 1]);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-1; j++) {
            cin >> rig[i][j];
        }
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            cin >> dwn[i][j];
        }
    }
    if (k % 2 == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << "-1 ";
            }
            cout << '\n';
        }
    } else {
        for (int i = 1; i <= k / 2; i++) upd(i);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << dist[i][j][k / 2] * 2 << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}