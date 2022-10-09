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
        ll n, s;
        cin >> n >> s;
        ll lo = (n - 1) / 2;
        ll hi = n - lo;

        cout << s / hi << '\n';
    }
}