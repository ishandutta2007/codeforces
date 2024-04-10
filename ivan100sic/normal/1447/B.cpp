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
        int n, m, neg = 0, sum = 0;
        cin >> n >> m;
        vector<int> a(n*m);
        for (int& x : a) {
            cin >> x;
            if (x < 0) {
                x = -x;
                neg++;
            }
            sum += x;
        }

        if (neg % 2) sum -= *R::min_element(a) * 2;
        cout << sum << '\n';
    }
    
}