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
        int k;
        cin >> k;
        k--;

        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        a[0]--;
        a[1]--;
        a[2]--;

        int m = 1 << k;
        for (int i : ra(0, 5)) {
            for (int j : ra(0, 3)) {
                if (m & (1 << j)) {
                    if (a[j] != -1) {
                        m |= 1 << a[j];
                    }
                }
            }
        }

        cout << (m == 7 ? "YES\n" : "NO\n");
    }
    
}