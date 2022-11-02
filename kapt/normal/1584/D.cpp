#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        int l = 1, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            cout << "? " << 1 << " " << m << endl;
            int x;
            cin >> x;
            if (x == 0) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << "? " << l << " " << n << endl;
        int x;
        cin >> x;
        cout << "? " << l + 1 << " " << n << endl;
        int y;
        cin >> y;
        int a = x - y + 1;
        x -= a * (a - 1) / 2;
        int i = l, j = l + a;
        l = 0, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (m * (m - 1) / 2 <= x) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << "! " << i << " " << j << " " << j + l - 1 << endl;
    }
    return 0;
}