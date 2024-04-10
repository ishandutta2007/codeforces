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

    vector<string> f = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    for (int x : ra(0, 18)) f.push_back(to_string(x));

    int t, z = 0;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (R::count(f, s)) {
            z++;
        }
    }
    cout << z << '\n';
}