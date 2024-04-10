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

        if (R::count(a, 0) == n) {
            cout << "0\n";
        } else {
            int l = 0, r = n-1;
            while (a[l] == 0) l++;
            while (a[r] == 0) r--;
            if (R::count(ra(l, r+1), 0, [&](int i) { return a[i]; }) == 0) {
                cout << "1\n";
            } else {
                cout << "2\n";
            }
        }
    }
    
}