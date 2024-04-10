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

    // int n;
    // cin >> n;

    // set<int> s;
    // for (int a : ra(1, n+1)) {
    //     for (int b : ra(a+1, n+1)) {
    //         int x = b*b-a*a;
    //         if (x <= n) {
    //             s.insert(x);
    //         }
    //     }
    // }

    // for (int x : s) cout << x << ' ';
    // cout << '\n';

    int n;
    cin >> n;
    if (n <= 2) {
        cout << n*2 + 1 << '\n';
    } else {
        n -= 3;
        cout << n/3*4 + n%3 + 7 << '\n'; 
    }
}