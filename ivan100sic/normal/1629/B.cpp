// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const string_view o[2] = {"NO", "YES"};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int l, r, k, z;
        cin >> l >> r >> k;
        if (l == r) {
            z = l > 1;
        } else {
            int d = (r+1)/2 - l/2;
            z = k >= d;
        }
        cout << o[z] << '\n';
    }
}