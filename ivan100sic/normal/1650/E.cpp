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
        int n, d;
        cin >> n >> d;
        vector a(n+1, 0);
        for (int i : ra(1, n+1)) cin >> a[i];
    
        multiset<int> ms;
        for (int i : ra(1, n+1)) {
            ms.insert(a[i] - a[i-1] - 1);
        }

        auto add = [&](int x) {
            ms.insert(x);
        };

        auto rem = [&](int x) {
            ms.erase(ms.find(x));
        };

        int sol = *ms.begin();
        for (int i : ra(1, n+1)) {
            if (i < n) {
                int d1 = a[i] - a[i-1] - 1;
                int d2 = a[i+1] - a[i] - 1;
                rem(d1);
                rem(d2);
                add(d1 + d2 + 1);
            } else {
                int d1 = a[i] - a[i-1] - 1;
                rem(d1);
            }

            // Solve
            int eg = i < n ? d - a[n] : d - a[n-1];
            // insert between two
            sol = max(sol, min(*ms.begin(), (*ms.rbegin() - 1) / 2));
            // insert at end
            sol = max(sol, min(*ms.begin(), eg - 1));

            
            // Undo
            if (i < n) {
                int d1 = a[i] - a[i-1] - 1;
                int d2 = a[i+1] - a[i] - 1;
                rem(d1 + d2 + 1);
                add(d2);
                add(d1);
            } else {
                int d1 = a[i] - a[i-1] - 1;
                add(d1);
            }
        }

        cout << sol << '\n';
    }
}