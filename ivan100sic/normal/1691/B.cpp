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
        vector<int> a(n), p(n);
        for (int& x : a) cin >> x;

        bool bad = 0;
        for (int i=0; i<n;) {
            int j = i;
            while (j+1 < n && a[j+1] == a[i]) {
                j++;
            }

            if (j == i) {
                bad = 1;
                break;
            }

            for (int k=i; k<j; k++) {
                p[k] = 2+k;
            }
            p[j] = i+1;
            i = j+1;
        }

        if (bad) {
            cout << "-1\n";
        } else {
            for (int x : p) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}