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

        int last = -1, f = 1;

        vector<int> a(n);
        for (int& x : a) cin >> x;
        
        for (int i : ra(0, n)) {
            int x = a[i];
            if (x == 0) {
                if (last == 0) {
                    f = -1;
                    break;
                } else if (last == 1) {
                    // nothing
                }
            } else {
                if (last == 1) {
                    f += 5;
                } else {
                    f += 1;
                }
            }
            last = x;
        }

        cout << f << '\n';
    }
    
}