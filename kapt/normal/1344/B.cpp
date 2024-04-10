#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3;
string arr[MAXN];

vector<int> g[MAXN * MAXN];
int used[MAXN * MAXN];

void dfs(int v) {
    used[v] = true;
    for (auto u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    bool f1 = false;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        if (arr[i][0] == '#') {
            cnt++;
        }
        if (arr[i][m - 1] == '#') {
            cnt++;
        }
        for (int j = 1; j < m; ++j) {
            if (arr[i][j] != arr[i][j - 1]) {
                cnt++;
            } else if (arr[i][j] == '#') {
                g[i * m + j].push_back(i * m + j - 1);
                g[i * m + j - 1].push_back(i * m + j);
            }
        }
        if (cnt == 0) {
            f1 = true;
        } else if (cnt != 2) {
            cout << -1;
            return 0;
        }
    }
    bool f2 = false;
    for (int j = 0; j < m; ++j) {
        int cnt = 0;
        if (arr[0][j] == '#') {
            cnt++;
        }
        if (arr[n - 1][j] == '#') {
            cnt++;
        }
        for (int i = 1; i < n; ++i) {
            if (arr[i][j] != arr[i - 1][j]) {
                cnt++;
            } else if (arr[i][j] == '#') {
                g[i * m + j].push_back(i * m + j - m);
                g[i * m + j - m].push_back(i * m + j);
            }
        }
        if (cnt == 0) {
            f2 = true;
        } else if (cnt != 2) {
            cout << -1;
            return 0;
        }
    }
    if ((f1 && !f2) || (!f1 && f2)) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n * m; ++i) {
        if (arr[i / m][i % m] == '#') {
            if (!used[i]) {
                dfs(i);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}