#include <bits/stdc++.h>

using namespace std;

int xv, yv, xp, yp;

int main() {
    cin >> xp >> yp >> xv >> yv;
    int A = xp + yp;
    int B = max(xv, yv);
    if (A <= B || (xp <= xv && yp <= yv))
        cout << "Polycarp\n";
    else
        cout << "Vasiliy\n";
    return 0;
}