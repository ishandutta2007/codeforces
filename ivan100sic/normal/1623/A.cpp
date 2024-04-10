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
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;
        int sol = 1e9;

        if (rb <= rd) sol = min(sol, rd - rb);
        else sol = min(sol, 2*n-rd-rb);

        if (cb <= cd) sol = min(sol, cd - cb);
        else sol = min(sol, 2*m-cd-cb);

        cout << sol << "\n";
    }
}