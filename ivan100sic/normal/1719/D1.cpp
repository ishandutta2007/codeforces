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

        vector<int> d(n+1);
        d[0] = 0;
        // num bonus
        
        map<int, int> mp;
        mp[0] = 0;
        int z = 0;
        for (int i : ra(0, n)) {
            if (a[i] == 0) {
                d[i+1] = d[i] + 1;
            } else {
                z ^= a[i];
                auto it = mp.find(z);
                if (it != mp.end()) {
                    d[i+1] = max(d[i], it->second + 1);
                } else {
                    d[i+1] = d[i];
                }
            }
            mp[z] = d[i+1];
        }

        cout << n - d[n] << '\n';
    }
}