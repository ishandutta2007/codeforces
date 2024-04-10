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
        vector<pair<int, int>> a(n);
        for (int i : ra(0, n)) {
            cin >> a[i].first;
            a[i].second = i + 1;
        }
        R::sort(R::reverse_view(a));
        vector<int> sol(n+1);
        int l = 0, r = 0;
        bool dir = 1;
        ll val = 0;
        for (int i : ra(0, n)) {
            int x = a[i].second;
            if  (dir) sol[x] = --l;
            else sol[x] = ++r;
            val += (1ll + i/2) * a[i].first; 
            dir ^= 1;
        }

        cout << 2*val << '\n';
        for (int x : sol) cout << x << ' ';
        cout << '\n';
    }
}