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
        int n, k;
        string s;
        cin >> n >> k >> s;

        auto p = s;
        R::reverse(p);

        int a;
        if (k == 0) {
            a = 1;
        } else {
            if (p == s) {
                a = 1;
            } else {
                a = 2;
            }
        }

        cout << a << '\n'; 
    }
}