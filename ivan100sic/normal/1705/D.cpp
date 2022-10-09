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

        vector<int> u, v;
        for (int i : ra(0, n-1)) {
            if (a[i] != a[i+1]) u.push_back(i);
            if (b[i] != b[i+1]) v.push_back(i);
        }

        if (u.size() != v.size() || a[0] != b[0] || a.back() != b.back()) {
            cout << "-1\n";
        } else {
            ll z = 0;
            for (int i : ra(0, ssize(u))) {
                z += abs(u[i] - v[i]);
            }
            cout << z << '\n';
        }
    }
    
}