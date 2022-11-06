#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    if (__gcd(x, y) > 1) {
        cout << "Impossible\n";
        return 0;
    }
    while (x > 0 && y > 0)  {
        if (x > y) {
            long long m = x / y;
            x -= m * y;
            if (y == 1) m -= 1;
            cout << m << 'A';
        } else {
            long long m = y / x;
            y -= m * x;
            if (x == 1) m -= 1;
            cout << m << 'B';
        }
    }
}