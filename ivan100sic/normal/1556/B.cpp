// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll radi(const vector<int>& c, int b) {
    vector<int> d[2];
    int n = c.size();

    for (int i=0; i<n; i++) {
        int t = (b + i) % 2;
        if (t != c[i]) {
            d[c[i]].push_back(i);
        }
    }

    ll z = 0;

    for (int i=0; i<(int)d[0].size(); i++) {
        z += abs(d[0][i] - d[1][i]);
    }

    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int c[2] = {0, 0};
        for (int& x : a) {
            cin >> x;
            x %= 2;
            c[x]++;
        }

        ll sol;
        if (n % 2) {
            if (c[0] - c[1] == 1) {
                sol = radi(a, 0); 
            } else if (c[1] - c[0] == 1) {
                sol = radi(a, 1);
            } else {
                sol = -1;
            }
        } else {
            if (c[0] != c[1]) {
                sol = -1;
            } else {
                sol = min(radi(a, 0), radi(a, 1));
            }
        }

        cout << sol << '\n';
    }
}