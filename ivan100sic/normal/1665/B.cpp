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
        map<int, int> mp;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            mp[x]++;
        }

        int h = 0;
        for (auto [k, v] : mp) {
            h = max(h, v);
        }

        int z = n - h; // swaps

        int t = h;
        while (t < n) {
            // clone
            t *= 2;
            z++;
        }
        
        cout << z << '\n';
    }
}