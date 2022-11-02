#include <bits/stdc++.h>
using namespace std;

main() {
    int x, y, z;
    cin >> x >> y >> z;
    int mn = x - y - z;
    int mx = x - y + z;
    if (mx < 0) {
        cout << "-";
    } else if (mn > 0) {
        cout << "+";
    } else if (mn == 0 && mx == 0) {
        cout << "0";
    } else {
        cout << "?";
    }
    return 0;
}