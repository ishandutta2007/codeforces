#include <bits/stdc++.h>
using namespace std;
vector<int> v(200000);
vector<int> ans(200000);
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> v[i];
    bool ok = 1;
    int last = n + 1;
    for (int i = m; i > 0 && ok; i--) {
        int pos = min(n - v[i] + 1, last - 1);
        if (pos < 1)
            ok = 0;
        else {
            ans[i] = pos;
            last = pos;
        }
    }
    if (!ok) {
        cout << -1;
        return 0;
    }
    ans[1] = 1;
    int k = 2;
    if (m == 1 && v[1] == n) {
        cout << 1;
        return 0;
    }
    while (k <= m && ans[k] > ans[k - 1] + v[k - 1]) {
        ans[k] = ans[k - 1] + v[k - 1];
        k++;
    }
    if (k == m + 1) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i];
        if (i != m) cout << ' ';
    }
}