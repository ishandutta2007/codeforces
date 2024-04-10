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
        vector<int> a(n+1);
        for (int i : ra(0, n)) cin >> a[i+1];

        for (int i : ra(1, n+1)) {
            if (a[i] != i) {
                int j = R::find(a, i) - begin(a);
                reverse(begin(a) + i, begin(a) + j + 1);
                break;
            }
        }

        for (int x : span(a).subspan(1)) cout << x << ' ';
        cout << '\n';
    }
}