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
        // a 01    0 <     1 >
        // b 10
        // any seq of 01
        int n, a, b;
        cin >> n >> a >> b;

        vector<int> d;
        if (a == b) {
            for (int i : ra(0, a)) {
                d.push_back(0);
                d.push_back(1);
            }
            d.push_back(0);
        } else if (a == b + 1) {
            for (int i : ra(0, a)) {
                d.push_back(0);
                d.push_back(1);
            }
        } else if (b == a + 1) {
            for (int i : ra(0, b)) {
                d.push_back(1);
                d.push_back(0);
            }
        } else {
            cout << "-1\n";
            continue;
        }

        if (ssize(d) > n - 1) {
            cout << "-1\n";
            continue;
        }

        while (ssize(d) != n - 1) {
            d.push_back(d.size() ? d.back() : 0);
        }

        vector<int> sol(n);
        int l = 0, r = 0;
        for (int i : ra(1, n)) {
            if (d[i-1]) sol[i] = --l;
            else sol[i] = ++r;
        }

        for (int& x : sol) x += 1-l;
        for (int x : sol) {
            cout << x << ' ';
        }
        cout << '\n';
    }    
}