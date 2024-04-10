#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        if (n < 6) {
            n = 6;
        } else {
            n += n % 2;
        }
        cout << n / 2 * 5 << "\n";
    }
    return 0;
}