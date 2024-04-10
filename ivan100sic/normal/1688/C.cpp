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
        char x = 0;
        for (int i : ra(0, 2*n+1)) {
            string s;
            cin >> s;
            for (char c : s) {
                x ^= c;
            }
        }

        cout << x << '\n';
    }
}