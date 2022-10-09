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
        int x, y;
        cin >> x >> y;
        if ((x+y) % 2) {
            cout << "-1 -1\n";
        } else if (x > y) {
            cout << (x+y)/2 << " 0\n";
        } else {
            cout << "0 " << (x+y)/2 << '\n';
        }
    }
}