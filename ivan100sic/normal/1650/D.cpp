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
        for (int& x : a) cin >> x, x--;

        vector<int> d(n);
        for (int i=n-1; i>=0; i--) {
            int j = R::find(a, i) - begin(a);
            if (j != i) {
                rotate(begin(a), begin(a) + j + 1, begin(a) + i + 1);
                d[i] = j+1;
            }
        }

        for (int x : d) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}