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
        int n, d, s = 0;
        cin >> n >> d;
        vector<int> a(n);
        for (int& x : a) cin >> x, s += x;

        if (d == 1) {
            cout << "-1\n";
        } else if (s % d) {
            cout << n << '\n';
        } else {
            int i = 0, j = n-1;
            while (i < n && a[i] % d == 0) i++;
            while (j >= 0 && a[j] % d == 0) j--;
            if (i == n) {
                cout << "-1\n";
            } else {
                cout << max(n-i-1, j) << '\n';
            }
        }
    }
}