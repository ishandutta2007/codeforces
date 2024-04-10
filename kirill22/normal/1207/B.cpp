#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int b[n][m];
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[i][j] = 0;
        }
    }
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] != a[i][j]) {
                if (b[i][j] == 0 && i < n - 1 && j < m - 1) {
                    b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
                    ans.push_back({i + 1, j + 1});
                }
                else {
                    cout << -1;
                    return 0;
                }
            }
            else {
                if (b[i][j] == 1) {
                    if (i < n - 1 && j < m - 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1) {
                        b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
                        ans.push_back({i + 1, j + 1});
                    }
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto c : ans) {
        cout << c.first << " " << c.second << endl;
    }
}