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

        vector<int> b(n+1);
        for (int i : ra(0, n)) {
            if (a[i]) {
                b[max(0, i - a[i] + 1)]++;
                b[i+1]--;
            }
        }

        for (int i=0, z=0; i<n; i++) {
            z += b[i];
            cout << !!z << ' ';
        }
        cout << '\n';
    }
    
}