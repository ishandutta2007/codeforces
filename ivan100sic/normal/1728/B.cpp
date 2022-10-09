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
        if (n % 2 == 0) {
            for (int i=n-2; i>=1; i--) {
                cout << i << ' ';
            }
            cout << n-1 << ' ' << n << '\n';
        } else if (n == 1) {
            cout << "1\n";
        } else if (n == 3) {
            cout << "2 1 3\n";
        } else {
            cout << "1 2 3 ";
            for (int i=n-2; i>=4; i--) {
                cout << i << ' ';
            }
            cout << n-1 << ' ' << n << '\n';
        }
    }
    
}