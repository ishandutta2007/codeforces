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
        int n;
        cin >> n;
        int m[2][2] = {0};
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            m[i%2][x%2]++;
        }

        if ((m[0][0] && m[0][1]) || (m[1][0] && m[1][1])) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    
}