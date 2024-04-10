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
        int n, d, sol = 0;
        cin >> n >> d;

        int l = 1'123'123'123;
        int r = -l;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            l = min(l, x);
            r = max(r, x);
            if (r-l > 2*d) {
                l = r = x;
                sol++;
            }
        }

        cout << sol << '\n';
    }
    
}