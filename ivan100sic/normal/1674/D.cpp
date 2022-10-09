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

        for (int i = n%2; i+1 < n; i+=2) {
            if (a[i] > a[i+1]) {
                swap(a[i], a[i+1]);
            }
        }

        cout << (R::is_sorted(a) ? "YES\n" : "NO\n");
    }
}