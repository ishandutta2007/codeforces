#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, x;
        cin >> n >> x;
        vector<pair<int, int>> a(n);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int c, d;
            cin  >> c >> d;
            mx = max(mx, c);
            a[i] = {c - d, c};
        }
        sort(a.begin(), a.end());
        int ans = 1;
        x -= mx;
        if (x <= 0) {
            cout << 1 << endl;
            continue;
        }
        if (a[n - 1].first <= 0) {
            cout << -1 << endl;
            continue;
        }
        ans += (x + a[n - 1].first - 1) / a[n - 1].first;
        cout << ans << endl;
    }
}