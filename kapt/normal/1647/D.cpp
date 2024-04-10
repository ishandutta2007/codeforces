#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, d;
        cin >> n >> d;
        if (d == 1) {
            cout << "NO" << endl;
            continue;
        }
        int cnt = 0;
        while (n % d == 0) {
            n /= d;
            cnt++;
        }
        if (cnt == 1) {
            cout << "NO" << endl;
            continue;
        }
        bool f = false;
        for (int k = 2; k * k <= n; ++k) {
            if (n % k == 0) {
                f = true;
            }
        }
        if (f) {
            cout << "YES" << endl;
            continue;
        }
        if (cnt == 2) {
            cout << "NO" << endl;
            continue;
        }
        int t = 1 - f;
        f = false;
        for (int k = 2; k * k <= d; ++k) {
            if (d % k == 0) {
                f = true;
            }
        }
        if (!f) {
            cout << "NO" << endl;
            continue;
        }
        if (cnt >= 4) {
            cout << "YES" << endl;
            continue;
        }
        f = false;
        for (int b = 2; b * b <= d; ++b) {
            if (d % b == 0) {
                if (b * n % d != 0) {
                    f = true;
                }
                if (d / b * n % d != 0) {
                    f = true;
                }
            }
        }
        if (f) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}