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
        vector<int> a(n), b[2];
        for (int& x : a) cin >> x, b[x % 2].push_back(x);

        int i = 0, j = 0, k = 0;
        R::sort(a);
        for (int x : a) {
            if (i < ssize(b[0]) && b[0][i] == x) {
                i++, k++;
            } else if (j < ssize(b[1]) && b[1][j] == x) {
                j++, k++;
            }
        }
        cout << (k == n ? "Yes\n" : "No\n");
    }
}