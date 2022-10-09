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
        ll n, x, t;
        cin >> n >> x >> t;
        ll c = t / x;
        if (n <= c) {
            cout << n * (n - 1) / 2 << '\n'; 
        } else {
            cout << c * (c - 1) / 2 + (n - c) * c << '\n';
        }
    }
}