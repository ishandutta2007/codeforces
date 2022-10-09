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
        int n, a, b;
        cin >> n >> a >> b;

        vector<int> c(n);
        c[0] = a;
        c[n-1] = b;

        int j = 1;
        for (int i : ra(1, n-1)) {
            while (j == a || j == b) j++;
            c[i] = j++;
        }

        sort(c.rbegin() + 1, c.rend() - 1);

        if (*min_element(c.begin(), c.begin() + n/2) == a &&
            *max_element(c.begin() + n/2, c.end()) == b)
        {
            for (int x : c) cout << x << ' ';
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }
    
}