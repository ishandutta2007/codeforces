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
        vector<int> f(n), s(n);
        for (int& x : s) cin >> x;
        for (int& x : f) cin >> x;
    
        for (int i : ra(0, n)) {
            if (i == 0) {
                cout << f[0] - s[0] << ' ';
            } else {
                cout << f[i] - max(s[i], f[i-1]) << ' ';
            }
        }
        cout << '\n';
    }
    
}