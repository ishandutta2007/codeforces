// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

using table = bitset<2048>;

table ones(int n) {
    table t;
    for (int i=0; i<n; i++) {
        t.set(i);
    }
    return t;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        auto moze = [&](int m) {
            table t = ones(m), d = t;
            for (int x : a) {
                d = ((d >> x) | (d << x)) & t;
            }
            return d.count() != 0;
        };

        int l = 0, r = 2021, o = 2022;
        while (l <= r) {
            int m = (l+r) / 2;
            if (moze(m)) {
                o = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        cout << o-1 << '\n';
    }
}