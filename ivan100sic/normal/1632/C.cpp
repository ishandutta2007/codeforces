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
        int a, b;
        cin >> a >> b;
        int sol = b-a;

        for (int x=b; x<=2*b; x++) {
            for (int y=a; y<=10000000; y+=y&-y) {
                sol = min(sol, (y-a) + (x-b) + 1 + ((x|y)-x));
            }
        }

        cout << sol << '\n';
    }
}