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
        ll x;
        cin >> x;
        ll s = ceil(sqrt(x - 0.5));
        ll i = x - (s-1)*(s-1);
        if (i <= s) {
            cout << i << ' ' << s << '\n';
        } else {
            cout << s << ' ' << 2*s - i << '\n';
        }
    }
}