#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<bool>> used;
char a[1000][1000];

void dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= used.size() || j >= used[0].size()) return;
    if (used[i][j] || a[i][j] != '#') return;
    used[i][j] = true;
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    used.resize(n, vector<bool> (m, false));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '.') cnt++;
        }
    }
    if (cnt == n * m) {
        cout << 0;
        return 0;
    }
    if (n == 1 || m == 1) {
        bool f = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != '#') f = false;
            }
        }
        if (f) cout << 1;
        else cout << -1;
        return 0;
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int l = -1, r = -1;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') {
                l = j;
                r = j;
                while (r + 1 < m && a[i][r + 1] == '#') r++;
                break;
            }
        }
        for (int j = 0; j < m; j++) {
            if (l != -1 && a[i][j] == '#' && (j < l || j > r)) {
                cout << -1;
                return 0;
            }
        }
        if (l != -1) x++;
    }
    for (int i = 0; i < m; i++) {
        int l = -1, r = -1;
        for (int j = 0; j < n; j++) {
            if (a[j][i] == '#') {
                l = j;
                r = j;
                while (r + 1 < n && a[r + 1][i] == '#') r++;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (l != -1 && a[j][i] == '#' && (j < l || j > r)) {
                cout << -1;
                return 0;
            }
        }
        if (l != -1) y++;
    }
    if (x == n && y < m) {
        cout << -1;
        exit(0);
    }
    if (x < n && y == m) {
        cout << -1;
        exit(0);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#' && !used[i][j]) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
}