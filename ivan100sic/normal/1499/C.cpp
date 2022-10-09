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
        ll n;
        cin >> n;
        vector<ll> c(n);
        for (ll& x : c) cin >> x;

        ll el = c[0], ol = 2e9, es = c[0], os = 0, sol = 1e18;
        for (int i=1; i<n; i++) {
            ll& x = (i % 2 ? ol : el);
            x = min(x, c[i]);
            (i % 2 ? os : es) += c[i];

            sol = min(sol, el * (n - i/2) + ol * (n - (i-1) / 2) + es-el + os-ol);
        }
        
        cout << sol << '\n';
    }
}