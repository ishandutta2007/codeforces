#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define all(a) a.begin(), a.end()

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    char a[n][m];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '.') cnt++;
        }
    }
    if (x * 2 <= y) {
        cout << x * cnt << endl;
        return;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '.') continue;
            if (j < m - 1 && a[i][j + 1] == '.') {
                a[i][j] = a[i][j + 1] = '#';
                ans += y;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') ans += x;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}