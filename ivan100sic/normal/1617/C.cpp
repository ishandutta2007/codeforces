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
        bool ok = 1;
        int sol = 0;
        for (int& x : a) cin >> x;
        R::sort(a);
        for (int i : ra(0, n)) {
            if (a[i] < i+1) {
                ok = 0;
                break;
            }
        }

        vector<bool> f(n+1);
        vector<int> b, c;
        for (int x : a) {
            if (x <= n) {
                if (f[x] == 1) {
                    b.push_back(x);
                } else {
                    f[x] = 1;
                }
            } else {
                b.push_back(x);
            }
        }

        for (int i=1; i<=n; i++) {
            if (!f[i]) c.push_back(i);
        }

        R::sort(b);
        R::sort(c);

        for (int i : ra(0, ssize(b))) {
            if (b[i] <= 2*c[i]) {
                ok = 0;
            } else {
                sol++;
            }
        }

        if (!ok) sol = -1;
        cout << sol << '\n';
    }
    
}