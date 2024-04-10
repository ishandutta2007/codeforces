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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        for (int& x : a) {
            int y;
            cin >> y;
            x = y - x;
        }

        R::sort(a, greater<>{});
        
        cout << -1 + *R::lower_bound(ra(0, n/2+2), true, {}, [&](int m) {
            if (2*m > n) return true;
            for (int i : ra(0, m)) {
                if (a[i] + a[2*m-1-i] < 0) {
                    return true;
                }
            }
            return false;
        }) << '\n';
    }
}