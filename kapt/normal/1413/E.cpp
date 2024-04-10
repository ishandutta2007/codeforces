#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int q = c / d;
        if (a > c * b) {
            cout << -1 << endl;
            continue;
        }
        int x = (a - 1) / (d * b);
        cout << a * (x + 1) - x * (x + 1) / 2 * d * b << endl;
    }
    return 0;
}