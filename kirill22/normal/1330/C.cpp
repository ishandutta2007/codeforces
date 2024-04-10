#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    vector<int> ans;
    int l = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        if (l + 1 < i + 1) {
            cout << -1;
            return 0;
        }
        int r = min(l - 1, n - a[i] - 1);
        int _l = max(l - a[i], i -  1);
        if (_l <= r) {
            l = _l;
        }
        else {
            cout << -1;
            return 0;
        }
        ans.push_back(l + 1);
    }
    if (l != -1) {
        cout << -1;
        return 0;
    }
    for (int i = m - 1; i >= 0; i--) {
        cout << ans[i] + 1 << " ";
    }
}