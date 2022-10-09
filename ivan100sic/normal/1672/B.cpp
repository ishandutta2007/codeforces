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
        string u, a = "YES\n";
        cin >> u;
        int z = 0;
        for (char c : u) {
            z += c == 'A' ? 1 : -1;
            if (z < 0) {
                a = "NO\n";
            }
        } 
        if (u.back() != 'B') a = "NO\n";
        cout << a;
    }
}