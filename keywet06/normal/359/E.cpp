#include <bits/stdc++.h>

const int N = 505;

using namespace std;

bool b[N][N];

int rx0, ry0, n;
int a[N][N];

vector<char> res;

bool up(int x, int y, int v, int u) {
    bool res = false;
    for (int j = y + u, i = x + v; i >= 1 && i <= n && j >= 1 && j <= n;
         j = j + u, i = i + v) {
        if (a[i][j] > 0) {
            res = true;
            break;
        }
    }
    return res;
}

void dfs(int x, int y, char g) {
    b[x][y] = true;
    if (a[x][y] == 0) {
        res.push_back('1');
        a[x][y] = 1;
    }
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (!b[x + i][y + j] && (abs(i) + abs(j) == 1) &&
                (1 <= i + x && i + x <= n) && (1 <= j + y && j + y <= n) &&
                up(x, y, i, j)) {
                char c;
                if (i == 1) c = 'D';
                if (i == -1) c = 'U';
                if (j == 1) c = 'R';
                if (j == -1) c = 'L';
                res.push_back(c);
                if (i == 1) c = 'U';
                if (i == -1) c = 'D';
                if (j == 1) c = 'L';
                if (j == -1) c = 'R';
                dfs(x + i, y + j, c);
            }
        }
    }
    a[x][y] = 0;
    res.push_back('2');
    if (g != '3') res.push_back(g);
}

int solve() {
    dfs(rx0, ry0, '3');
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] > 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < res.size(); ++i) printf("%c", res[i]);
    cout << endl;
    return 0;
}

int main() {
    scanf("%d %d %d", &n, &rx0, &ry0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) scanf("%d", &a[i + 1][j + 1]);
    }
    return solve();
}