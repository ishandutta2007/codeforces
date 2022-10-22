#include <bits/stdc++.h>
using namespace std;

int main() {

    long long a, b;
    cin >> a >> b;

    double sol1, sol2;
    long long x1 = (a-b)/b - 1*( (a-b)/b % 2 != 0 );
    long long x2 = (a+b)/b - 1*( (a+b)/b % 2 != 0 );

    sol1 = double( a-b ) / x1, sol2 = double( a+b ) / x2;

    cout << fixed << setprecision(10) << ( b > a ? -1 : ( sol1 < sol2 ? sol1 : sol2 ) );
    return 0;
}