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

        int z = 0;
        while (1) {
            int j = -1;
            for (int i=n-1; i>=0; i--) {
                if (a[i] != a[n-1]) {
                    j = i;
                    break;
                }
            }
            if (j == -1) {
                break;
            }

            z++;
            int l = n-1-j;
            if (2*l > n) {
                // last one
                break;
            }

            int k = j-l+1;
            for (int x : ra(0, l)) {
                a[k+x] = a[k+x+l];
            }
        }

        cout << z << '\n';
    }
}