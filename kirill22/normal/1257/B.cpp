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
        int x, y;
        cin >> x >> y;
        bool f = false;
        if (x >= y) {
            f = true;
        }
        if (x >= 4) {
            f = true;
        }
        if (x == 2 && y == 3) {
            f = true;
        }
        if (f) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}