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
        vector<int> r(n);
        for (int& x : r) {
            cin >> x;
        }

        int m;
        cin >> m;
        vector<int> b(m);
        for (int& x : b) {
            cin >> x;
        }

        int rr = 0, bb = 0, z = 0;
        for (int x : r) {
            z += x;
            rr = max(rr, z);
        }

        z = 0;
        for (int x : b) {
            z += x;
            bb = max(bb, z);
        }

        cout << rr + bb << '\n';
    }
    
}