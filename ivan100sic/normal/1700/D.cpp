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

    ll sum = 0;
    ll hi = 0;

    int n;
    cin >> n;
    for (int i : ra(0, n)) {
        int x;
        cin >> x;
        sum += x;
        hi = max(hi, (sum + i) / (i + 1));
    }

    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;

        if (x < hi) {
            cout << "-1\n";
        } else {
            cout << (sum + x - 1) / x << '\n';
        }
    }
}