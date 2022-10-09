// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    ll x, y, m;
    cin >> x >> y >> m;
    if (max(x, y) >= m) {
        cout << "0\n";
        return 0;
    }

    if (x > y) {
        swap(x, y);
    }

    if (y <= 0) {
        cout << "-1\n";
        return 0;
    }

    ll z = 0;
    if (x < 0) {
        z = abs(x) / y;
        x += y * z;
    }

    while (max(x, y) < m) {
        x += y;
        z++;
        if (x > y) {
            swap(x, y);
        }
    }

    cout << z << '\n';
}