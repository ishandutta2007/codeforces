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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        R::sort(a);
        ll s = accumulate(begin(a), end(a), 0ll) * 2;
        s += n;
        for (int i : ra(1, n)) {
            s -= min(a[i], a[i-1]);
        }
        s -= a[0];
        cout << (s <= m ? "YES\n" : "NO\n");
    }
}