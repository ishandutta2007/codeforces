#include <bits/stdc++.h>

using namespace std;

const int N = 13;

long double x, y, z, a[N], b[N];

int main() {
    cin >> x >> y >> z;
    a[1] = x, b[1] = pow(y, z);
    a[2] = x, b[2] = pow(z, y);
    a[3] = x, b[3] = y * z;
    a[4] = x, b[4] = z * y;
    a[5] = y, b[5] = pow(x, z);
    a[6] = y, b[6] = pow(z, x);
    a[7] = y, b[7] = x * z;
    a[8] = y, b[8] = z * x;
    a[9] = z, b[9] = pow(x, y);
    a[10] = z, b[10] = pow(y, x);
    a[11] = z, b[11] = x * y;
    a[12] = z, b[12] = y * x;
    int ind = 1;
    for (int i = 1; i <= 12; ++i) {
        if (log(a[i]) * b[i] > log(a[ind]) * b[ind]) ind = i;
    }
    if (ind == 1) cout << "x^y^z";
    if (ind == 2) cout << "x^z^y";
    if (ind == 3) cout << "(x^y)^z";
    if (ind == 4) cout << "(x^z)^y";
    if (ind == 5) cout << "y^x^z";
    if (ind == 6) cout << "y^z^x";
    if (ind == 7) cout << "(y^x)^z";
    if (ind == 8) cout << "(y^z)^x";
    if (ind == 9) cout << "z^x^y";
    if (ind == 10) cout << "z^y^x";
    if (ind == 11) cout << "(z^x)^y";
    if (ind == 12) cout << "(z^y)^x";
}