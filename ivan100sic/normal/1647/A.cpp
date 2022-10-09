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
        int x;
        cin >> x;

        if (x % 3 == 0) {
            for (int i : ra(0, x/3)) {
                cout << "21";
            }
        } else if (x % 3 == 1) {
            cout << '1';
            for (int i : ra(0, x/3)) {
                cout << "21";
            }
        } else {
            cout << '2';
            for (int i : ra(0, x/3)) {
                cout << "12";
            }
        }

        cout << '\n';
    }
}