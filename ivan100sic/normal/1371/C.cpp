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
        ll a, b, n, m;
        cin >> a >> b >> n >> m;

        bool ans;
        if (m > min(a, b)) {
            ans = false;
        } else {
            ans = a+b >= n+m;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
    
}