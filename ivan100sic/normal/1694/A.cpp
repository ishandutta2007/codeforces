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
        int a, b;
        cin >> a >> b;
        string s;
        for (int i : ra(0, a+b)) {
            if (a && b) {
                s += i % 2 ? '0' : '1';
                (i % 2 ? a : b)--;
            } else if (a) {
                s += '0';
            } else {
                s += '1';
            }
        }
        cout << s << '\n';
    }
}