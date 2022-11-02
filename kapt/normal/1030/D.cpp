#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int n, m, k;
    cin >> n >> m >> k;
    if (n * m * 2 % k) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    if (k % 2 == 0) {
        int g = __gcd(n, k / 2);
        cout << "0 0" << endl;
        cout << n / g << " 0" << endl;
        cout << "0 " << m / (k / 2 / g);
    } else {
        int g = __gcd(n, k);
        cout << "0 0" << endl;
        if (g == 1) {
            cout << n << " 0" << endl;
            cout << "0 " << m / k * 2;
        } else {
            cout << n / g * 2 << " 0" << endl;
            cout << "0 " << m / (k / g);
        }
    }
    return 0;
}