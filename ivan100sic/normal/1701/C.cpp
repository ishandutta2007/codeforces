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
        vector<int> a(m);
        for (int& x : a) cin >> x, x--;

        cout << *R::lower_bound(ra(0, 2*m+1), true, {}, [&](int q) {
            vector<int> left(n, q);
            int unused = 0;
            for (int x : a) {
                if (left[x] > 0) {
                    left[x]--;
                } else {
                    unused++;
                }
            }

            ll total_left = 0;
            for (int x : left) total_left += x/2;

            return unused <= total_left;
        }) << '\n';
    }
}