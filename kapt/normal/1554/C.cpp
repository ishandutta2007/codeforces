#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        int x = 0;
        for (int i = 29; i >= 0; --i) {
            if (n & (1 << i)) {
                if (m & (1 << i)) {
                    continue;
                } else {
                    break;
                }
            } else {
                if (m & (1 << i)) {
                    x |= (1 << i);
                } else {
                    continue;
                }
            }
        }
        if ((n ^ x) == m) {
            for (int i = 0; i <= 30; ++i) {
                if ((n & (1ll << i)) == 0) {
                    if ((m & (1ll << i)) == 0) {
                        x |= (1ll << i);
                        break;
                    }
                }
                if (x & (1ll << i)) {
                    x ^= (1ll << i);
                }
            }
        }
        cout << x << "\n";
    }
    return 0;
}