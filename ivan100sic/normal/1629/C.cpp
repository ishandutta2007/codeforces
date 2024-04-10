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
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        vector<vector<int>> e(n+1);
        
        set<int> s;
        for (int x : ra(0, n+1)) s.insert(x);

        for (int i : ra(0, n)) {
            e[a[i]].push_back(i);
        }

        for (int i=n-1; i>=0; i--) {
            s.erase(a[i]);
            b[i] = *s.begin();
        }

        int l = 0;
        vector<int> sol;
        while (l < n) {
            int x = b[l];
            sol.push_back(x);
            int r = l;
            for (int i : ra(0, x)) {
                r = max(r, *R::lower_bound(e[i], l));
            }
            l = r+1;
        }

        cout << size(sol) << '\n';
        for (int x : sol) cout << x << ' ';
        cout << '\n';
    }
}