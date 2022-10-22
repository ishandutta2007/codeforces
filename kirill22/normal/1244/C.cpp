#include<bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    int x1, y1;
    int g = gcd(b % a, a, x1, y1);
    y = x1, x = y1 - x1 * (b / a);
    return g;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p, w, d;
    cin >> n >> p >> w >> d;
    if (p % __gcd(w, d) != 0) {
        cout << -1;
        exit(0);
    }
    int x, y;
    int g = gcd(w, d, x, y);
    int m = w / g;
    y = (((y % m) * ((p / g) % m)) % m + m) % m;
    x = (p - (y * d)) / w;
    if (x + y > n || x < 0) {
        cout << -1;
        exit(0);
    }
    cout << x << " " << y << " " << n - x - y;
}