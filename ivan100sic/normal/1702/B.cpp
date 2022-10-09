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
        set<char> se;
        int sol = 0;
        for (char c : s) {
            if (!se.contains(c) && se.size() == 3) {
                se = {};
                sol++;
            }
            se.insert(c);
        }
        cout << sol + !!se.size() << '\n';
    }
    
}