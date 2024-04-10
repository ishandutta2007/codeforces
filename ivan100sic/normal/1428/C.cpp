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
        string p;
        for (char c : s) {
            p += c;
            while (p.ends_with("AB") || p.ends_with("BB")) {
                p.pop_back();
                p.pop_back();
            }
        }
        cout << size(p) << '\n';
    }
}