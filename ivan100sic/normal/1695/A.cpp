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
        int n, m;
        cin >> n >> m;

        int xh=-1123123123, ih=-1, jh=-1;
        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                int x;
                cin >> x;
                if (x > xh) {
                    xh = x;
                    ih = i;
                    jh = j;
                }
            }
        }

        cout << max(jh+1, m-jh) * max(ih+1, n-ih) << '\n';
    }
}