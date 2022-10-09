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

        if (n == 1) {
            cout << "1\n";
            continue;
        }
        
        deque<int> dq1 = {n};

        int l = 0, r = n - 1;
        if (a[l] == n) {
            l++;
        } else if (a[r] == n) {
            r--;
        } else {
            cout << "-1\n";
            continue;
        }

        while (l < r) {
            if (a[l] < a[r]) {
                dq1.push_front(a[l++]);
            } else {
                dq1.push_back(a[r--]);
            }
        }

        bool fo = 0;

        for (int f : {0, 1}) {
            auto dq = dq1;
            f ? dq.push_front(a[l]) : dq.push_back(a[l]);

            deque<int> b;
            int le = 0, re = n-1;
            while (le < re) {
                if (dq[le] < dq[re]) {
                    b.push_front(dq[le++]);
                } else {
                    b.push_back(dq[re--]);
                }
            }

            auto c = b, d = b;
            c.push_back(n);
            d.push_front(n);
            if (vector(begin(c), end(c)) == a || vector(begin(d), end(d)) == a) {
                for (int x : dq) {
                    cout << x << ' ';
                }
                cout << '\n';
                fo = 1;
                break;
            }
        }

        if (!fo) {
            cout << "-1\n";
        }
    }
}