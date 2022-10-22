#include <bits/stdc++.h>

using namespace std;

#define int long long

int INF = 1e18;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int g[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '0') {
                g[i][j] = 0;
            }
            else {
                g[i][j] = 1;
            }
        }
    }
    int dp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dp[i][j] = 0;
            }
            else if(g[i][j]) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = INF;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][k] != INF && dp[k][j] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
    int m;
    cin >> m;
    vector<int> a(m);
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
    }
    ans.push_back(a[0]);
    for (int i = 1; i < m - 1; i++) {
        if (dp[ans[ans.size() - 1]][a[i + 1]] != dp[ans[ans.size() - 1]][a[i]] + dp[a[i]][a[i + 1]]) {
            ans.push_back(a[i]);
        }
    }
    ans.push_back(a[m - 1]);
    cout << ans.size() << endl;
    for (auto c : ans) {
        cout << c + 1 << " ";
    }
}