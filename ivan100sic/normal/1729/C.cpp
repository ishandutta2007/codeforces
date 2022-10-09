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
        int n = ssize(s);

        vector<int> v(n);
        iota(begin(v), end(v), 0);

        if (s[0] > s[n-1]) {
            for (char& c : s) {
                c = 128 - c;
            }
        }

        R::sort(v, [&](int x, int y) {
            return pair(s[x], x) < pair(s[y], y);
        });

        int l = R::find(v, 0) - begin(v);
        int r = R::find(v, n-1) - begin(v);

        cout << abs(s[0] - s[n-1]) << ' ' << r-l+1 << '\n';
        for (int i : ra(l, r+1)) {
            cout << v[i]+1 << " \n"[i == r];
        }
    }
}