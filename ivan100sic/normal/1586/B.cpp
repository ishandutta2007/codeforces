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
        int n, m;
        cin >> n >> m;
        vector f(n+1, 1);
        for (int i : ra(0, m)) {
            int a, b, c;
            cin >> a >> b >> c;
            f[b] = 0;
        }

        for (int x : ra(1, n+1)) {
            if (f[x] == 1) {
                for (int i : ra(1, n+1)) {
                    if (i != x) {
                        cout << x << ' ' << i << '\n';
                    }
                }
                break;
            }
        }
    }
    
}