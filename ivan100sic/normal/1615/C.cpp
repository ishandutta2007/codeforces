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
        string a, b;
        cin >> n >> a >> b;

        if (a == b) {
            cout << "0\n";
            continue;
        }

        int x = R::count(a, '1');
        int y = R::count(b, '1');
        int diff = [&]() {
            int c = 0;
            for (int i : ra(0, n)) c += a[i] != b[i];
            return c;
        }();

        if (!x) {
            cout << "-1\n";
            continue;
        }

        int sol = 123123123;
        if (x == y) {
            // direct
            sol = min(sol, diff);
        }

        if (n-x+1 == y) {
            // flipped
            for (int i : ra(0, n)) {
                if (a[i] == '1' && b[i] == '1') {
                    sol = min(sol, n-diff);
                }
            }
            sol = min(sol, n-diff+2);
        }

        if (sol == 123123123) sol = -1;
        cout << sol << '\n';
    }
    
}