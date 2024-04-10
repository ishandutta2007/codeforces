// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int ev(string_view s) {
    int k = 0;
    for (char c : s) {
        if (c == 'X') k++;
        else if (c == 'S') k = -(k+1);
        else if (c == 'L') k++;
    }
    
    return k;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;

        int u = ev(a), v = ev(b);

        if (u < v) {
            cout << '<';
        } else if (u == v) {
            cout << '=';
        } else {
            cout << '>';
        }

        cout << '\n';
    }
    
}