#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ans = 0, mx = 0, ii = 0;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = 0; j < n; j++) {
            if ((a[i] & (a[i] ^ a[j])) > 0) {
                k++;
            }
        }
        c[i] = k;
        if (k > mx) {
            ii = i;
            mx = k;
        }
    }
    for (int x = n; x > 0; x--) {
        if (mx != x - 1) {
            if (x > 1) {
                for (auto l : b) {
                    ans += l;
                }
            }
            cout << ans;
            return 0;
        }
        b[ii] = 0;
        c[ii] = -1;
        int ii2 = ii;
        mx = 0, ii = 0;
        for (int j = 0; j < n; j++) {
            if ((a[j] & (a[j] ^ a[ii2])) > 0) {
                c[j]--;
            }
            if (c[j] > mx) {
                ii = j;
                mx = c[j];
            }
        }
    }
    cout << 0;
}