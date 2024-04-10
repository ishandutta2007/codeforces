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
        map<int, int> lo, hi;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            if (!lo.contains(x)) {
                lo[x] = i;
            }
            hi[x] = i;
        }

        while (k--) {
            int a, b;
            cin >> a >> b;
            if (lo.contains(a) && hi.contains(b) && lo[a] <= hi[b]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    
}