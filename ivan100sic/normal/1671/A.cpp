// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const string forbidden[] = {
    "xab",
    "xba",
    "abx",
    "bax",
    "bab",
    "aba",
    "xax",
    "xbx",
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        s = "x" + s + "x";
        if (R::any_of(forbidden, [&](string f) {
            return s.find(f) != s.npos;
        })) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}