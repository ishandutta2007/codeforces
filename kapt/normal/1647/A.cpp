#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        if (n % 3 == 1) {
            cout << 1;
            n--;
            while (n) {
                cout << 21;
                n -= 3;
            }
        } else {
            while (n >= 3) {
                cout << 21;
                n -= 3;
            }
            if (n) {
                cout << 2;
            }
        }
        cout << "\n";
    }
    return 0;
}