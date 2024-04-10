#include <bits/stdc++.h>
using namespace std;

main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        if (n < 4) {
            cout << 4 - n << endl;
        } else if (n % 2 == 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}