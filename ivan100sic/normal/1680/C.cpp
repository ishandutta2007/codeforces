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
        vector<int> c1(n+1);
        for (int i : ra(0, n)) {
            c1[i+1] = c1[i] + (s[i] == '1');
        }

        int l = c1[n];
        int sol = 1e9;
        for (int i : ra(0, n-l+1)) {
            int w1 = c1[i+l] - c1[i];
            int w0 = l - w1;
            sol = min(sol, w0);
        }

        cout << sol << '\n';
    }
}