#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans = 2e9 + 5;
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        int d = a[i] - a[i - 1];
        if (d < ans) {
            ans = d;
            cnt = 1;
        } else if (d == ans) {
            ++cnt;
        }
    }
    cout << ans << ' ' << cnt << endl;
}