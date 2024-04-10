#include <bits/stdc++.h>
using namespace std;

main() {
    int t;
    cin >> t;
    int n, x, y, d;
    for (int i = 0; i < t; ++i) {
        cin >> n >> x >> y >> d;
        if (x % d != y % d) {
            if (y % d == n % d && y % d == 1 % d) {
                cout << min((y - 1) / d + (x - 1 + d - 1) / d, (n - y) / d + (n - x + d - 1) / d) << endl;
            } else if (y % d == n % d) {
                cout << (n - y) / d + (n - x + d - 1) / d << endl;
            } else if (y % d == 1 % d) {
                cout << (y - 1) / d + (x - 1 + d - 1) / d << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            cout << abs(y - x) / d << endl;
        }
    }
    return 0;
}