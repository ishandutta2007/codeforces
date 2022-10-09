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
        if (t.find('a') != t.npos) {
            if (t == "a") {
                cout << "1\n";
            } else {
                cout << "-1\n";
            }
        } else {
            cout << (1ull << s.size()) << '\n';
        }
    }
}