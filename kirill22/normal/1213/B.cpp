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
        int n, ans = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int m = a[n - 1];
        for (int i = n - 2;  i >= 0; i--) {
            if (a[i] > m) {
                ans++;
            }
            m = min(a[i], m);
        }
        cout << ans << endl;
    }
}