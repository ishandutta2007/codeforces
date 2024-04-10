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
        ll A, B;
        cin >> A >> B >> n;

        vector<pair<ll, ll>> a(n);
        for (int i : ra(0, n)) cin >> a[i].first;
        for (int i : ra(0, n)) cin >> a[i].second;

        ll hleft = B;
        for (int i : ra(0, n)) {
            ll hits = (a[i].second + A - 1) / A;
            hleft -= hits * a[i].first;
        }

        if (hleft >= 0) {
            cout << "YES\n";
        } else {
            bool f = 0;
            for (int i : ra(0, n)) {
                if (a[i].first + hleft > 0) {
                    f = true;
                    break;
                }
            }

            cout << (f ? "YES\n" : "NO\n");
        }
    }
    
}