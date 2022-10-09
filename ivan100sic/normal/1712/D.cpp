// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int inf = 1'000'000'000;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        // maximize max(2*min, min(ai, aii))

        vector<int> a(n);
        for (int& x : a) cin >> x;

        cout << *R::lower_bound(ra(0, inf+1), true, {}, [&](int m) {
            int mvs = 0;
            auto b = a;
            for (int i=0; i<n; i++) {
                if (b[i] * 2 < m) {
                    mvs++;
                    b[i] = inf; 
                }
            }

            // Two consecutive >= m?
            for (int i : ra(0, n-1)) {
                if (b[i] >= m && b[i+1] >= m) {
                    return mvs > k;
                }
            }

            // Any >= m?
            if (R::count_if(b, [&](int x) { return x >= m; })) {
                return mvs + 1 > k;
            }

            return mvs + 2 > k;
        }) - 1 << '\n';
    }
}