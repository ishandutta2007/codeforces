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
        string s;
        cin >> s;
        vector<int> d(27, -123123123);
        d[0] = 0;
        for (char x : s) {
            int dl = d[x-96];
            d[x-96] = max(dl, d[0] + 1);
            d[0] = max(d[0], dl + 1);
        }
        cout << ssize(s) - d[0] << '\n';
    }
}