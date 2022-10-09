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
        int s = 0;
        for (int i : ra(0, 4)) {
            int x;
            cin >> x;
            s += x;
        }

        cout << !!s + (s == 4) << '\n';
    }
}