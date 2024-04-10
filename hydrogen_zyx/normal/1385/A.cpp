#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a = 0, b = 0, c = 0;
        int x = 0, y = 0, z = 0;
        cin >> x >> y >> z;
        int cnt = 0;
        if (x == z && x >= y) {
            b = x;
            cnt++;
        } else
            b = min(x, z);
        if (x == y && x >= z) {
            a = x;
            cnt++;
        } else {
            a = min(x, y);
        }
        if (y == z && y >= x) {
            c = y;
            cnt++;
        } else {
            c = min(y, z);
        }
        if (cnt == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << a << ' ' << b << ' ' << c << endl;
        }
    }
}