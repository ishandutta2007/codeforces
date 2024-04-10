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
        vector<int> h(n);
        for (int i : ra(0, n)) cin >> h[i];

        vector<ll> ql, qr;
        for (int i=1; i+1<n; i+=2) {
            ql.push_back(max(0, max(h[i-1], h[i+1]) + 1 - h[i]));
        }
        R::reverse(h);
        for (int i=1; i+1<n; i+=2) {
            qr.push_back(max(0, max(h[i-1], h[i+1]) + 1 - h[i]));
        }
        R::reverse(h);

        if (n % 2) {
            cout << accumulate(begin(ql), end(ql), 0ll) << '\n';
        } else {
            ql.insert(ql.begin(), 0);
            for (int i : ra(1, ssize(ql))) ql[i] += ql[i-1];

            qr.insert(qr.begin(), 0);
            for (int i : ra(1, ssize(qr))) qr[i] += qr[i-1];

            ll sol = 1e18;
            for (int j : ra(0, ssize(ql))) {
                sol = min(sol, ql[j] + qr[ssize(ql) - 1 - j]);
            }
            
            cout << sol << '\n';
        }
    }
    
}