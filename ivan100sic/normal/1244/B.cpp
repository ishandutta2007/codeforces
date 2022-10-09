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
        string s;
        cin >> n >> s;

        int f = -1, l = -1;
        for (int i : ra(0, n)) {
            if (f == -1 && s[i] == '1') f = i;
            if (s[i] == '1') l = i;
        }

        if (f == -1) {
            cout << n << '\n';
        } else {
            cout << 2 * max(l+1, n-f) << '\n';
        }
    }
    
}