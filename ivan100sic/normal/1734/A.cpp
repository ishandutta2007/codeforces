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

        R::sort(a);
        int sol = 2012012012;
        for (int i : ra(0, n-2)) {
            auto b = span(a).subspan(i, 3);
            sol = min(sol, b[2] - b[0]);
        }

        cout << sol << '\n';
    }
    
}