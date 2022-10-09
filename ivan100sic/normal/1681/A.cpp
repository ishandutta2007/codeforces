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
        int n, m;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        cin >> m;
        vector<int> b(m);
        for (int& x : b) cin >> x;

        int ha = *R::max_element(a);
        int hb = *R::max_element(b);

        if (ha >= hb) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }

        if (hb >= ha) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
}