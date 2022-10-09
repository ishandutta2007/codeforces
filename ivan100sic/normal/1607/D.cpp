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
        vector<int> a(n), rv, bv;
        for (int& x : a) cin >> x;
        string s;
        cin >> s;

        for (int i : ra(0, n)) {
            (s[i] == 'R' ? rv : bv).push_back(a[i]);
        }

        string ans = "YES";
        R::sort(bv);
        for (int i : ra(0, ssize(bv))) {
            if (bv[i] <= i) {
                ans = "NO";
            }
        }

        R::sort(rv, greater<int>());
        for (int i : ra(0, ssize(rv))) {
            if (rv[i] > n-i) {
                ans = "NO";
            }
        }

        cout << ans << '\n';
    }
    
}