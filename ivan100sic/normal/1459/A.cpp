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
        int n, u=0, v=0;
        cin >> n;
        string a, b;
        cin >> a >> b;
        for (int i : ra(0, n)) {
            if (a[i] > b[i]) u++;
            else if (a[i] < b[i]) v++;
        }

        if (u > v) cout << "RED\n";
        else if (u < v) cout << "BLUE\n";
        else cout << "EQUAL\n";
    }
    
}