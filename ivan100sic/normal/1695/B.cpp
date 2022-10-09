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

        if (n % 2) {
            cout << "Mike\n";
        } else {
            int l[2] = {0, 1};
            for (int i : ra(0, n)) {
                if (a[i] < a[l[i%2]]) {
                    l[i%2] = i;
                }
            }

            if (tie(a[l[0]], l[0]) > tie(a[l[1]], l[1])) {
                cout << "Mike\n";
            } else {
                cout << "Joe\n";
            }
        }
    }
}