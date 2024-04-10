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

        int l = 1, r = n - 1, o = n;
        while (l <= r) {
            int m = (l+r) / 2;
            cout << "? 1 " << m << '\n' << flush;
            
            int cnt = 0;
            for (int i : ra(0, m)) {
                int x;
                cin >> x;
                if (x <= m) {
                    cnt++;
                }
            }

            if (cnt % 2) {
                o = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        cout << "! " << o << '\n' << flush;
    }
}