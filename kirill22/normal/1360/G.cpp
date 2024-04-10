#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(a) a.begin(), a.end()

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n * a != m * b) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int ans[n][m];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ans[i][j] = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        int z = a;
        while (z--) {
            ans[i][k] = 1;
            k = (k + 1) % m;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}