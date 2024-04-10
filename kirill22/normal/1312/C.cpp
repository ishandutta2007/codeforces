#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> z(100);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 100; j++) {
                z[j] += a[i] % k;
                a[i] /= k;
            }
        }
        bool f = true;
        for (int i = 0 ; i < 100; i++) {
            if (z[i] > 1) f = false;
        }
        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}