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
        int n, c = 0;
        cin >> n;
        vector<ll> a(n);
        for (ll& x : a) {
            cin >> x;
            while (x % 2 == 0) {
                x /= 2;
                c++;
            }
        }

        R::sort(a);
        a[n-1] <<= c;
        cout << accumulate(begin(a), end(a), 0ll) << '\n';
    }
    
}