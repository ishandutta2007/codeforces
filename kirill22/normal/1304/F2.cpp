#include<bits/stdc++.h>

using namespace std;

int t[80000], d[80000];

void push(int v, int l, int r) {
    t[v] += d[v];
    if (l + 1 != r) {
        d[v * 2 + 1] += d[v];
        d[v * 2 + 2] += d[v];
    }
    d[v] = 0;
}

void update(int v, int l, int r, int l1, int r1, int x) {
    push(v, l, r);
    if (l1 >= r || l >= r1) return;
    if (l1 <= l && r <= r1) {
        d[v] += x;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    update(v * 2 + 1, l, m, l1, r1, x);
    update(v * 2 + 2, m, r, l1, r1, x);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int a[n][m], pref[n][m + 1];
    for (int i = 0; i < n; i++) {
        pref[i][0] = 0;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            pref[i][j + 1] = pref[i][j] + a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for (int i = 0; i + k - 1 < m; i++) {
        dp[0][i] = pref[0][i + k] - pref[0][i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 4 * m; j++) d[j] = 0, t[j] = 0;
        for (int j = 0; j + k - 1 < m; j++) {
            update(0, 0, m, j, j + 1, dp[i - 1][j] + pref[i][j + k] - pref[i][max(j, k)]);
        }
        for (int j = 0; j + k - 1 < m; j++) {
            dp[i][j] = t[0] + pref[i][j + k] - pref[i][j];
            update(0, 0, m, j - k + 1, j + 1, +a[i][j]);
            if (j + k < m) {
                update(0, 0, m, j + 1, j + k + 1, -a[i][j + k]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) ans = max(ans, dp[n - 1][i]);
    cout << ans;
}