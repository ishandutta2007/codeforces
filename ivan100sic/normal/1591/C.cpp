// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll solve(vector<int>& a, int k) {
    vector<int> b, c;
    for (int x : a) {
        (x > 0 ? b : c).push_back(abs(x));
    }
    R::sort(b, greater<int>());
    R::sort(c, greater<int>());

    ll sol = 0;
    for (int i=0; i<ssize(b); i+=k) sol += 2*b[i];
    for (int i=0; i<ssize(c); i+=k) sol += 2*c[i];

    if (b.size() && c.size()) sol -= max(b[0], c[0]);
    else if (b.size()) sol -= b[0];
    else if (c.size()) sol -= c[0];
    return sol;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        ll sol = solve(a, k);
        cout << sol << '\n';
    }
}
/*
1
9 3
-5 -10 -15 6 5 8 3 7 4
*/