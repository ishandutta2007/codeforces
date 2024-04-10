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

    set<int> sq;
    for (int x=0; x<=1000; x++) {
        sq.insert(x*x);
    }

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int d2 = x*x + y*y;

        if (d2 == 0) {
            cout << "0\n";
        } else if (sq.contains(d2)) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
    
}