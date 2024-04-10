// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll ask(int l, int r) {
    cout << "? " << l << ' ' << r << '\n' << flush;
    ll x;
    cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll tot = ask(1, n);
        int k = *R::lower_bound(ra(1, n), true, {}, [&](int m) {
            return ask(1, m) == tot;
        });

        int w2 = ask(1, k) - ask(1, k-1) + 1;
        int j = k - w2;
        int w1 = ask(1, j) - ask(1, j-1) + 1;
        int i = j - w1 + 1;

        cout << "! " << i << ' ' << j+1 << ' ' << k << '\n' << flush;
    }
}