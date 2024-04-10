// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

/*
w, l

w % a <= 2
l % a <= 2

*/

void divs(vector<int>& a, int x) {
    if (x < 1) return;

    for (int i=1; i*i<=x; i++) {
        if (x % i == 0) {
            a.push_back(i);
            a.push_back(x/i);
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int w, l;
        cin >> w >> l;

        vector<int> a, b;
        for (int i : {0, 1, 2}) {
            divs(a, w-i);
            divs(a, l-i);
        }

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        for (int x : a) {
            int p[3], q[3];
            for (int i : {0, 1, 2}) {
                p[i] = w >= i && (w-i) % x == 0;
                q[i] = l >= i && (l-i) % x == 0;
            }

            int can = 0;
            auto go = [&] {
                if (p[0]) {
                    can |= p[2] && q[1];
                    can |= q[2];
                    can |= p[1] && q[1] && q[2];
                }
                can |= p[1] && q[1];
            };

            go();
            R::swap_ranges(p, q);            
            go();

            if (can) b.push_back(x);
        }

        cout << b.size();
        for (int x : b) {
            cout << ' ' << x;
        }
        cout << '\n';
    }
}