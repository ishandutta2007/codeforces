// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll n, k, z = 0;
        cin >> n >> k;
        ll x = 1;

        while (x < n && x < k) {
            x += min(k, x);
            z++;
        }
        
        if (x < n) {
            z += (n-x+k-1) / k;
        }

        cout << z << '\n';
    }
    
}