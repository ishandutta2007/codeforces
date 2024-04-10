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
        int n, l;
        cin >> n >> l;
        vector<int> c(l);
        for (int _i : ra(0, n)) {
            int x;
            cin >> x;
            for (int i=0; i<l; i++) {
                c[i] += x & 1;
                x >>= 1;
            }
        }
        int z = 0;
        for (int i=0; i<l; i++) {
            if (c[i] > n-c[i]) {
                z |= 1 << i;
            }
        }          
        cout << z << '\n';      
    }
}