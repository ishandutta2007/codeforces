#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "a" << endl;
            continue;
        }
        for (int i = 0; i < (n - 2) / 2; ++i) {
            cout << "a";
        }
        cout << "b";
        if (n % 2) {
            cout << "c";
        }
        for (int i = 0; i < n / 2; ++i) {
            cout << "a";
        }
        cout << endl;
    }
    return 0;
}