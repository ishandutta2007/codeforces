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
        int n, k;
        cin >> n >> k;
        map<int, int> m;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            m[x]++;
        }

        int streak = 0, sol = -1, r = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it != m.begin() && prev(it)->first + 1 == it->first && it->second >= k) {
                streak += 1;
            } else if (it->second >= k) {
                streak = 1;
            } else {
                streak = 0;
            }

            if (streak > sol) {
                sol = streak;
                r = it->first;
            }
        }

        if (sol <= 0) {
            cout << "-1\n";
        } else {
            cout << r-sol+1 << ' ' << r << '\n';
        }
    }
}