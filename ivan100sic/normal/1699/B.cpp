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
        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                cout << ((i+j+i/2+j/2) % 2) << " \n"[j == m-1];
            }
        }
    }
}