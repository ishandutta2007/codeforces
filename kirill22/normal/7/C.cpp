#include<bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    int x1, y1;
    int g = gcd(b % a, a, x1, y1);
    y = x1;
    x = (y1 - x1 * (b / a));
    return g;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    int g = gcd(a, b, x, y);
    if (abs(c) % g != 0) {
        cout << -1;
        return 0;
    }
    a /= g;
    b /= g;
    c /= g;
    x *= (-c);
    y *= (-c);
    cout << x << " " << y;
}