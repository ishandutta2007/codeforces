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
        int c1 = R::count(a, 1);
        int d1 = R::adjacent_find(a, [](int x, int y) { return y == x + 1; }) != a.end();
        
        cout << (c1 && d1 ? "NO\n" : "YES\n");        
    }
}