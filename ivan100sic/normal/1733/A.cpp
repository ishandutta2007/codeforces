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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<int> h(k);
        for (int i : ra(0, n)) {
            h[i % k] = max(h[i % k], a[i]);
        }

        cout << accumulate(begin(h), end(h), 0ll) << '\n';
    }
}