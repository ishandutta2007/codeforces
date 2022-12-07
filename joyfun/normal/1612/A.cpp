#include <bits/stdc++.h>
using namespace std;

int t, x, y;

int main() {
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if ((x + y) % 2 != 0) {
            cout << "-1 -1" << endl;
        } else {
            cout << x / 2 << " " << y / 2 + x % 2 << endl;
        }
    }
    return 0;
}