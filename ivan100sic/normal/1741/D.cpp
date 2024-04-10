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

        int sol = 0;
        while (a.size() > 1) {
            vector<int> b;
            for (int i=0; i<ssize(a); i+=2) {
                int x = a[i], y = a[i+1], h = max(x, y);

                if (abs(x-y) != 1 || h % 2) {
                    sol = -1;
                    break;
                }

                b.push_back(h/2);
                if (x > y) {
                    sol++;
                }
            }

            if (sol == -1) {
                break;
            }
            
            swap(a, b);
        }

        cout << sol << '\n';
    }
}