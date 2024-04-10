#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k, s = 0;
        cin >> k >> n;
        vector<int> a(1000, 0), b(1000, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s += x;
            int z = 0;
            while (x % 2 == 0) {
                z++;
                x /= 2;
            }
            a[z]++;
        }
        for (int i = 900; i >= 0; i--) {
            b[i] = b[i + 1] + a[i];
        }
        if (s < k) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        bool f = false;
        for (int i = 0; i < 500; i++) {
            //cout << i << " " << a[i] << endl;
            if (f) ans++;
            if (f && a[i] > 0) {
                a[i]--;
                f = false;
            }
            if (k % 2 == 0) {
                a[i + 1] += a[i] / 2;
                b[i + 1] += a[i] / 2;
                k /= 2;
                continue;
            }
            if (a[i] > 0) {
                a[i + 1] += (a[i] - 1) / 2;
                b[i + 1] += (a[i] - 1) / 2;
                k /= 2;
                continue;
            }
            f = true;
            k /= 2;
        }
        cout << ans << endl;
    }
}