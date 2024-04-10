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
        string s, t;
        cin >> s >> t;
        if (t != "abc") {
            R::sort(s);
            cout << s << '\n';
        } else {
            if (R::count(s, 'a') && R::count(s, 'b') && R::count(s, 'c')) {
                R::sort(s, [](char a, char b) {
                    if (a == 'c' || a == 'b') a = 'b' + 'c' - a;
                    if (b == 'c' || b == 'b') b = 'b' + 'c' - b;
                    return a < b;
                });
            } else {
                R::sort(s);
            }
            
            cout << s << '\n';
        }
    }
}