#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t t;
    cin >> t;
    while (t--) {
        int64_t x, y, a, b;
        cin >> x >> y >> a >> b;
        int64_t diff = y-x;
        int64_t delta = a+b;
        if (diff % delta == 0) {
            cout << diff/delta << endl;
        } else {
            cout << -1 << endl;
        }
    }
}