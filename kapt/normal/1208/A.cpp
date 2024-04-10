#include <bits/stdc++.h>
using namespace std;

main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b, n;
        cin >> a >> b >> n;
        if (n % 3 == 0) {
            cout << a << endl;
        } else if (n % 3 == 1) {
            cout << b << endl;
        } else {
            cout << (a ^ b) << endl;
        }
    }
    return 0;
}