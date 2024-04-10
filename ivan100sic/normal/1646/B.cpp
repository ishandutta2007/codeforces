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
        int c = (n-1)/2;
        ll x = accumulate(a.end() - c, a.end(), 0ll);
        ll y = accumulate(a.begin(), a.begin() + c + 1, 0ll);
        if (x > y) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}