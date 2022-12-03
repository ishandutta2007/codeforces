#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        int mx = 0, d = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            mx = max(mx, a);
            d = __gcd(d, a);
        }
        cout << mx / d << '\n';
    }
    return 0;
}