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
        int a, b, c;
        cin >> a >> b >> c;
        if (b > a && b - a > c) {
            cout << 0 << endl;
            continue;
        }
        if (b > a) {
            c -= b - a;
            a = b;
        }
        if (a - b > c) {
            cout << c + 1;
        }
        else if (a - b == c) {
            cout << c;
        }
        else {
            cout << (a - b) + (c - a + b - 1) / 2 + 1;
        }
        cout << endl;
    }
}