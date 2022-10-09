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
        string s;
        for (int i=9; i>=1; i--) {
            int d = min(n, i);
            s = to_string(d) + s;
            n -= d;
            if (n == 0) break;
        }
        cout << s << '\n';
    }
}