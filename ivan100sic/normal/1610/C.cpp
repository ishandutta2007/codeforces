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
        vector<int> a(n), b(n);
        for (int i : ra(0, n)) {
            cin >> a[i] >> b[i];
        }

        cout << -1 + *R::partition_point(ra(0, n+1), [&](int k) {
            int taken = 0;
            for (int i : ra(0, n)) {
                if (taken < k && taken <= b[i] && k - taken - 1 <= a[i]) {
                    taken++;
                }
            }

            return taken == k;
        }) << '\n';
    }
    
}