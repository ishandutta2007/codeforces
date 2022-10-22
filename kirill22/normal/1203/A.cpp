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
        int n;
        cin >> n;
        vector<int> a(n);
        bool f = true;
        int pos = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                pos = i;
            }
        }
        if (n == 1) {
            cout << "YES" << endl;
            continue;
        }
        int i = pos;
        if (a[(i + 1) % n] == 2 && n > 1) {
            int tmp = (i + 1) % n, k = 2;
            while (tmp != i) {
                if (a[tmp] != k) {
                    f = false;
                    break;
                }
                k++;
                tmp = (tmp + 1) % n;
            }
        }
        else if (a[(i - 1 + n) % n] == 2 && n > 1) {
            int tmp = (i - 1 + n) % n, k = 2;
            while (tmp != i) {
                if (a[tmp] != k) {
                    f = false;
                    break;
                }
                k++;
                tmp = (tmp - 1 + n) % n;
            }
        }
        else {
            f = false;
        }
        if (f) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

}