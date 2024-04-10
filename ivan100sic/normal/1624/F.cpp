// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int ask(int c) {
    cout << "+ " << c << '\n' << flush;
    int x;
    cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;

    int l = 1, r = n-1;
    int added = 0, reply = 0;
    while (l < r) {
        int m = (l+r+1) / 2;
        int to_add = ((n - m - added) % n + n) % n;
        
        if (to_add != 0) {
            reply = ask(to_add);
        }
        
        added += to_add;
        if (reply > added / n) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    cout << "! " << added + l << '\n' << flush;
}