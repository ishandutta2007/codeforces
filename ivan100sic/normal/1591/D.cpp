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
        vector<int> a(n), f(n);
        for (int& x : a) {
            cin >> x;
            x--;
            f[x]++;
        }

        if (*R::min_element(f) == 0) {
            cout << "YES\n";
            continue;
        }

        R::fill(f, 0);
        int c = 0;
        for (int i=0; i<n; i++) {
            if (!f[i]) {
                c++;
                for (int j=a[i]; j!=i; j=a[j]) {
                    f[j] = 1;
                }
                f[i] = 1;
            }
        }

        cout << ((n-c) % 2 == 0 ? "YES\n" : "NO\n");
    }
    
}