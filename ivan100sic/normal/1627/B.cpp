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
        int n, m;
        cin >> n >> m;
        vector<int> a;
        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                a.push_back(max(i, n-1-i) + max(j, m-1-j));
            }
        }
        R::sort(a);
        for (int x : a) cout << x << ' ';
        cout << '\n';
    }
    
}