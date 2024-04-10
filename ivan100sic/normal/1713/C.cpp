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

        vector<int> a(n, -1);

        int q = 4 * sqrt(n) + 10;
        int r = n-1;
        while (r >= 0) {
            while (q*q > r+r) q--;
            int w = 2*r-q*q;
            for (int i=0; i<=w; i++) {
                a[r-i] = q*q-(r-i);
            }
            r -= w+1;
        }

        for (int x : a) cout << x << ' ';
        cout << '\n';
    }
}