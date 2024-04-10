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
        int a[3] = {n/3-2, n/3-2, n/3-2};
        if (n % 3 == 0) {
            a[0] += 2;
            a[1] += 3;
            a[2] += 1;
        } else if (n % 3 == 1) {
            a[0] += 2;
            a[1] += 4;
            a[2] += 1;
        } else {
            a[0] += 3;
            a[1] += 4;
            a[2] += 1;
        }

        cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
    }
}