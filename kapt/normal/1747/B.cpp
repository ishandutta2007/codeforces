#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while(tst--) {
        int n;
        cin >> n;
        cout << (n + 1) / 2 << endl;
        int l = 1, r = n * 3;
        for (int i = 0; i < (n + 1) / 2; ++i) {
            cout << l << " " << r << endl;
            l += 3;
            r -= 3;
        }
    }
    return 0;
}