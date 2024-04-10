// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll gcdsum(ll x) {
    ll x0 = x;
    ll z = 0;
    while (x > 0) {
        z += x % 10;
        x /= 10;
    }
    return gcd(z, x0);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        while (gcdsum(n) == 1) n++;
        cout << n << '\n';
    }
}