// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int ask(int a, int b, int c) {
    cout << "? " << a+1 << ' ' << b+1 << ' ' << c+1 << '\n' << flush;
    int x;
    cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n/3);

        // QUERIES n/3
        for (int i=0; i<n; i+=3) {
            a[i/3] = ask(i, i+1, i+2);
        }

        int zero = R::find(a, 0) - begin(a);
        int ones = R::find(a, 1) - begin(a);

        // QUERIES 3
        int qa[3];
        for (int i : {0, 1, 2}) {
            qa[i] = ask(3*zero, 3*zero + 1, 3*ones + i);
        }

        // QUERIES 2
        int sure_zero = -1, sure_one = -1;
        if (R::count(qa, 0) == 3) {
            // we caught a zero
            sure_zero = 3*zero;

            if (ask(sure_zero, 3*ones, 3*ones + 1)) sure_one = 3*ones;
            else if (ask(sure_zero, 3*ones, 3*ones + 2)) sure_one = 3*ones; 
            else sure_one = 3*ones + 1;
        } else {
            // we caught a one
            sure_one = 3*ones + R::find(qa, 1) - begin(qa);

            if (ask(sure_one, 3*zero, 3*zero + 1) == 0) sure_zero = 3*zero;
            if (ask(sure_one, 3*zero, 3*zero + 2) == 0) sure_zero = 3*zero;
            else sure_zero = 3*zero + 1;
        }

        // QUERIES 2(n/3-2) + 4
        vector<int> ans = {sure_zero};

        auto manual = [&](int j) {
            if (ask(sure_zero, sure_one, j) == 0) ans.push_back(j);
        };

        for (int i : ra(0, n/3)) {
            if (sure_zero / 3 == i || sure_one / 3 == i) {
                // manual
                for (int j : ra(3*i, 3*i+3)) {
                    if (j == sure_zero || j == sure_one) continue;
                    manual(j);
                }
            } else {
                // 2-query wonder
                int domin = a[i] == 1 ? sure_one : sure_zero;
                int reces = a[i] == 1 ? sure_zero : sure_one;
                int a1 = ask(reces, 3*i, 3*i+1);
                if (a1 == a[i]) {
                    // both were a[i]
                    if (!a[i]) ans.push_back(3*i), ans.push_back(3*i+1);
                    manual(3*i+2);
                } else {
                    // one of them is a[i], other is not, the third one is a[i]
                    if (ask(sure_zero, sure_one, 3*i) == a[i]) {
                        if (!a[i]) ans.push_back(3*i);
                        else ans.push_back(3*i+1);
                    } else {
                        if (!a[i]) ans.push_back(3*i+1);
                        else ans.push_back(3*i);
                    }
                    // third one
                    if (!a[i]) ans.push_back(3*i+2);
                }
            }
        }

        R::sort(ans);
        cout << "! " << ans.size();
        for (int x : ans) cout << ' ' << x+1;
        cout << '\n' << flush;
    }
}