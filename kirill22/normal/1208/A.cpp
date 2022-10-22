#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int a, b, n;
        cin >> a >> b >> n;
        if (n % 3 == 0) {
            cout << a << endl;
        }
        if (n % 3 == 1) {
            cout << b << endl;
        }
        if (n % 3 == 2) {
            cout << (a ^ b) << endl;
        }
    }
}