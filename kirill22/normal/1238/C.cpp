#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int h, n;
        cin >> h >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (h == a[i]) {
                continue;
            }
            if (h - 1 > a[i]) {
                h = a[i] + 1;
            }
            if ((i + 1 < n && a[i + 1] == h - 2) || h <= 2) {
                h = a[i + 1];
            }
            else {
                ans++;
                h = h - 2;
            }
        }
        cout << ans << endl;
    }
}