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
        int n, z = 0;
        cin >> n;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            z += x - 1;
        }

        cout << (z % 2 ? "errorgorn\n" : "maomao90\n");
    }
}