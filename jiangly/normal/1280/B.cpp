#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    int ca = 0, cp = 0;
    int l = m, r = 0, u = n, d = 0;
    int la = m, ra = 0, ua = n, da = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'A') {
                ++ca;
                ua = min(ua, i);
                da = max(da, i);
                la = min(la, j);
                ra = max(ra, j);
            }
            if (a[i][j] == 'P') {
                ++cp;
                u = min(u, i);
                d = max(d, i);
                l = min(l, j);
                r = max(r, j);
            }
        }
    }
    if (cp == 0) {
        cout << 0 << "\n";
        return;
    }
    if (ca == 0) {
        cout << "MORTAL\n";
        return;
    }
    if (l != 0 || r != m - 1 || u != 0 || d != n - 1) {
        cout << 1 << "\n";
        return;
    }
    if (a[0][0] == 'A' || a[0][m - 1] == 'A' || a[n - 1][0] == 'A' || a[n - 1][m - 1] == 'A') {
        cout << 2 << "\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < m; ++j)
            if (a[i][j] == 'P')
                ok = false;
        if (ok) {
            cout << 2 << "\n";
            return;
        }
    }
    for (int i = 0; i < m; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j)
            if (a[j][i] == 'P')
                ok = false;
        if (ok) {
            cout << 2 << "\n";
            return;
        }
    }
    if (la != 0 && ra != m - 1 && ua != 0 && da != n - 1) {
        cout << 4 << "\n";
        return;
    }
    cout << 3 << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}