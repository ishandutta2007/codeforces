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
        string s, t;
        int sol = 0;
        cin >> s >> t;
        R::adjacent_find(t, [&](char x, char y) {
            sol += abs(R::find(s, x) - R::find(s, y));
            return false;
        });
        cout << sol << '\n';
    }
    
}