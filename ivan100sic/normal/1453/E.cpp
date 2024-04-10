// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
vector<int> e[200005];

int solve(int x, int p, int k) {
    vector<int> b;
    for (int y : e[x]) {
        if (y != p) {
            b.push_back(solve(y, x, k));
        }
    }

    if (b.empty()) return 0;

    // k or greater? no
    for (int x : b) if (x >= k) return k+1;

    // exactly k-1, only if root and only one
    {
        int ck = R::count(b, k-1);
        if (ck >= 2) return k+1;
        if (ck == 1) return x == 0 ? k : k+1;
    }
    
    // max is k-2
    return *R::min_element(b) + 1;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i : ra(0, n)) e[i] = {};
        for (int i : ra(1, n)) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        cout << *R::lower_bound(ra(1, n), true, {}, [&](int k) {
            return solve(0, 0, k) <= k;
        }) << '\n';
    }
    
}