#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(40, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            int tmp = 0;
            while (x % 2 == 0) {
                x /= 2;
                tmp++;
            }
            a[tmp]++;
        }
        bool f = false;
        for (int i = 0; i < 30; i++) {
            if (i == 11 && a[i] > 0) {
                f = true;
            }
            a[i + 1] += a[i] / 2;
        }
        if (f) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

}