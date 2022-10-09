// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        ll d = b - a;

        if (d == 0) {
            cout << "0 0\n";
            continue;
        }

        ll r = a % d;
        r = min(r, d - r);

        cout << d << ' ' << r << '\n';
    }
}