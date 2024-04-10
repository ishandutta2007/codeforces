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
        int n, s = 0;
        ll sq = 0;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x, s += x, sq += x*x;
        for (int& x : b) cin >> x, s += x, sq += x*x;

        bitset<10005> dp;
        dp[0] = 1;
        for (int i : ra(0, n)) {
            dp = (dp << a[i]) | (dp << b[i]);
        }

        int h = 2e9;
        for (int j : ra(0, 10005)) {
            if (dp[j]) {
                h = min(h, j*j + (s-j)*(s-j));
            }
        }

        cout << h + (n-2)*sq << '\n';
    }
}