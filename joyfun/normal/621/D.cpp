#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

const char ans[9][10] = {"x^y^z", "x^z^y", "(x^y)^z", "y^x^z", "y^z^x", "(y^x)^z", "z^x^y", "z^y^x", "(z^x)^y"};

long double a[9];
long double x, y, z;

int main() {
    cin >> x >> y >> z;
    a[0] = pow(y, z) * log(x);
    a[1] = pow(z, y) * log(x);
    a[2] = y * z * log(x);
    a[3] = pow(x, z) * log(y);
    a[4] = pow(z, x) * log(y);
    a[5] = x * z * log(y);
    a[6] = pow(x, y) * log(z);
    a[7] = pow(y, x) * log(z);
    a[8] = x * y * log(z);
    int ansv = 0;
    for (int i = 1; i < 9; i++)
        if (a[i] > a[ansv])
            ansv = i;
    printf("%s\n", ans[ansv]);
    return 0;
}