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
        string a, b;
        cin >> n >> a >> b;

        map<string, int> mp;

        for (int i : ra(0, n)) {
            string t = {a[i], b[n-1-i]};
            R::sort(t);
            mp[t]++;
        }

        int odd = 0;
        for (auto [k, v] : mp) {
            if (v % 2) {
                odd++;
                if (k[0] != k[1]) {
                    odd++;
                }
            }
        }

        cout << (odd <= 1 ? "YES\n" : "NO\n");
    }
}