#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        int a;
        cin >> a;
        bool f = true;
        for (int i = 1; i < n; ++i) {
            int b;
            cin >> b;
            if (b < a) {
                f = false;
            }
        }
        if (f) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
    return 0;
}