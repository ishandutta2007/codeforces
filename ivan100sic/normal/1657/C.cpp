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
        cin >> s;

        int state = 0, c = 0, r = n;
        for (char x : s) {
            if (state == 0) {
                if (x == '(') {
                    state = 1;
                } else {
                    state = 2;
                }
            } else if (state == 1) {
                state = 0;
                c += 1;
                r -= 2;
            } else {
                if (x == '(') {
                    state++;
                } else {
                    c += 1;
                    r -= state;
                    state = 0;
                }
            }
        }

        cout << c << ' ' << r << '\n';
    }
}