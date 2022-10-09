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
        ll a, b, n;
        cin >> n >> a >> b;
        int ok = 0;
        if (a > 1) {
            for (ll x = 1; x <= n; x *= a) {
                if ((n - x) % b == 0) {
                    ok = 1;
                }
            }
        } else {
            ok = (n - 1) % b == 0;
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}