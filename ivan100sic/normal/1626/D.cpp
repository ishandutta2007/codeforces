// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int cost(int x) {
    return bit_ceil(0u + x) - x;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n+1);
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            b[x]++;
        }
        b.erase(remove(begin(b), end(b), 0), b.end());

        int k = size(b);
        vector<int> f(k+1);
        partial_sum(begin(b), end(b), begin(f) + 1);

        int sol = 1 << 20;
        for (int i : ra(0, k+1)) {
            int z0 = cost(f[i]);
            for (int x=1; x<=2*n; x<<=1) {
                int y = upper_bound(begin(f), end(f), f[i] + x) - 1 - begin(f);
                int z = z0;
                z += cost(f[y] - f[i]);
                z += cost(n - f[y]);
                sol = min(sol, z);
            }
        }
        cout << sol << '\n';
    }
}