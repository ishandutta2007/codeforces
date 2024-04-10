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
        string s;
        cin >> s;

        if (s.back() % 2 == 0) {
            cout << "0\n";
        } else if (s[0] % 2 == 0) {
            cout << "1\n";
        } else if (R::count_if(s, [](char c) { return c % 2 == 0; }) > 0) {
            cout << "2\n";
        } else {
            cout << "-1\n";
        }
    }
}