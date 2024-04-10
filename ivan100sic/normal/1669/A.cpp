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
        int r, a = 0;
        cin >> r;
        if (r <= 1399) {
            a = 4;
        } else if (r <= 1599) {
            a = 3;
        } else if (r <= 1899) {
            a = 2;
        } else {
            a = 1;
        }

        cout << "Division " << a << '\n';
    }
    
}