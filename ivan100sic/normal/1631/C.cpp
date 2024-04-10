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
        int n, x;
        cin >> n >> x;
        if (x == 0) {
            for (int i : ra(0, n/2)) {
                cout << i << ' ' << n-1-i << '\n';
            }
        } else if (x != n-1) {
            cout << "0 " << n-1-x << '\n';
            cout << x << ' ' << n-1 << '\n';
            for (int i : ra(1, n/2)) {
                if (i != x && i != n-1-x) {
                    cout << i << ' ' << n-1-i << '\n';
                }
            }
        } else if (n == 4) {
            cout << "-1\n";
        } else {
            vector<int> used(n, 0);
            auto pr = [&](int x, int y) {
                used[x] = used[y] = 1;
                cout << x << ' ' << y << '\n';
            };

            pr(0, n/2-1);
            pr(n/2, n-1);
            for (int x=1; x!=n/4; x<<=1) {
                pr(x, n-1-2*x);
            }
            pr(n/4, n-2);

            for (int i : ra(0, n)) {
                if (!used[i]) {
                    pr(i, n-1-i);
                }
            }
        }
    }
}