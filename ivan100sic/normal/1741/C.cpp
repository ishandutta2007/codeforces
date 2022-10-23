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
        vector<int> a(n);
        for (int& x : a) cin >> x;

        int sol = n;
        for (int l : ra(1, n+1)) {
            int sum = accumulate(begin(a), begin(a) + l, 0);

            int cur = 0, tot = 0, thicc = 0, ok = 1;
            for (int x : a) {
                tot += x;
                cur += 1;
                if (tot > sum) {
                    ok = 0;
                    break;
                } else if (tot == sum) {
                    thicc = max(thicc, cur);
                    cur = tot = 0;
                }
            }

            if (ok && tot == 0) {
                sol = min(sol, thicc);
            }
        }

        cout << sol << '\n';
    }
}