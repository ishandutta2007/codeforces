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
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;

        if (count(begin(a), begin(a) + n-m+1, b[0]) && a.ends_with(b.substr(1))) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    
}