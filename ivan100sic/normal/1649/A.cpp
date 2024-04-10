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
        vector<int> a(n);
        for (int& x : a) cin >> x;

        int z = R::find(a, 0) - begin(a);
        if (z == n) {
            cout << "0\n";
        } else {
            int y = n-1;
            while (a[y] == 1) y--;
            cout << y-z+2 << '\n';
        }
    }
}