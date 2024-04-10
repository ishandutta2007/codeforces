// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int mod = 1'000'000'007;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll x, z = 0;
        cin >> x;
        for (ll t=1, k=1; t<=x; k++, t=lcm(t, k)) {
            z += x / t;
        }
        z += x;
        cout << z % mod << '\n';
    }
}