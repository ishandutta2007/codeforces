#include <bits/stdc++.h>

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[0]) {
            ans = max(ans, i);
        }
        if (a[i] != a.back()) {
            ans = max(ans, n - i - 1);
        }
    }
    cout << ans << endl;
}