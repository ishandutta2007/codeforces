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
        int n, r, b;
        cin >> n >> r >> b;

        int z = 0;
        for (int i : ra(0, n)) {
            z += b+1;
            if (z >= n+1) {
                z -= n+1;
                cout << 'B';
            } else {
                cout << 'R';
            }
        }
        cout << '\n';
    }
}