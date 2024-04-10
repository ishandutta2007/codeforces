#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m, k;
        cin >> n >> m >> k;
        int s = n * m - 4;
        bool f = true;
        for (int i = 0; i < k; ++i) {
            int t;
            cin >> t;
            if (i > s + k - t) f = false;
        }
        if (f) {
            cout << "YA" << endl;
        } else {
            cout << "TIDAK" << endl;
        }
    }
    return 0;
}