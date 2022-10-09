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

    string s;
    cin >> s;
    int c4 = R::count(s, '4');
    int c7 = R::count(s, '7');

    if (c4 && c4 >= c7) cout << "4\n";
    else if (c7 > 0) cout << "7\n";
    else cout << "-1\n";
}