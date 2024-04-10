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
        for (int& x : a) {
            cin >> x;
            if (x % 2) {
                x += x % 10;
            }

            if (x % 10 != 0) {
                while (x % 10 != 2) {
                    x += x % 10;
                }
            }
        }

        // r10
        bool f = 0;
        for (int x : a) {
            if (x % 10 == 0) {
                cout << (set<int>(begin(a), end(a)).size() == 1 ? "Yes\n" : "No\n");
                f = 1;
                break;
            }
        }

        if (f) {
            continue;
        }

        set<int> s;
        for (int x : a) {
            s.insert(x % 20);
        }

        if (s.size() == 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}