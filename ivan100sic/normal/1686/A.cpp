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
        int n, z = 0;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x, z += x;
    
        bool f = 0;
        for (int x : a) if (n*x == z) f = 1;
        cout << (f ? "YES\n" : "NO\n");
    }
}