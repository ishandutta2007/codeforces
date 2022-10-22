#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
       int n, p = -1, z = 0;
       cin >> n;
       int mx = -1e18, mx2 = 1e18;
       vector<int> a(n);
       for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (p != -1 && x != -1) {
                z = max(z, abs(p - x));
            }
            p = x;
            a[i] = x;
       }
       for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (i > 0 && a[i - 1] != -1) {
                    mx = max(mx, a[i - 1]);
                    mx2 = min(mx2, a[i - 1]);
                }
                if (i < n - 1 && a[i + 1] != -1) {
                    mx = max(mx, a[i + 1]);
                    mx2 = min(mx2, a[i + 1]);
                }
            }
       }
       if (mx == -1e18) {
            cout << "0 0" << endl;
            continue;
       }
       int ans = (mx + mx2) / 2;
       cout << max(z, max(abs(ans - mx), abs(ans - mx2))) << " " << ans << endl;
    }
}