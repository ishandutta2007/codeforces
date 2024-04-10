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
        int lgn;
        cin >> lgn;
        int n = 1 << lgn;

        vector<int> a(n);
        iota(begin(a), end(a), 1);

        while (a.size() > 1) {
            if (a.size() == 2) {
                cout << "? " << a[0] << ' ' << a[1] << '\n' << flush;
                int x;
                cin >> x;
                if (x == 1) {
                    a = {a[0]};
                } else {
                    a = {a[1]};
                }
            } else {
                span aa = a;
                vector<int> b;
                for (int i=0; i<ssize(a); i+=4) {
                    auto a = aa.data() + i;
                    cout << "? " << a[0] << ' ' << a[2] << '\n' << flush;
                    int x;
                    cin >> x;
                    if (x == 1) {
                        cout << "? " << a[0] << ' ' << a[3] << '\n' << flush;
                        int y;
                        cin >> y;
                        if (y == 1) {
                            b.push_back(a[0]);
                        } else {
                            b.push_back(a[3]);
                        }
                    } else if (x == 2) {
                        cout << "? " << a[1] << ' ' << a[2] << '\n' << flush;
                        int y;
                        cin >> y;
                        if (y == 1) {
                            b.push_back(a[1]);
                        } else {
                            b.push_back(a[2]);
                        }
                    } else {
                        cout << "? " << a[1] << ' ' << a[3] << '\n' << flush;
                        int y;
                        cin >> y;
                        if (y == 1) {
                            b.push_back(a[1]);
                        } else {
                            b.push_back(a[3]);
                        }
                    }
                }

                swap(a, b);
            }
        }

        cout << "! " << a[0] << '\n' << flush;
    }
}