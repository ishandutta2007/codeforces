// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n), b(m);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        int p = 0, q = 0;
        bool ok = true;
        vector<int> sol;
        while (p < n || q < m) {
            bool first;
            if (p == n) first = false;
            else if (q == m) first = true;
            else first = a[p] < b[q];

            int v = first ? a[p++] : b[q++];
            if (v == 0) {
                sol.push_back(v);
                k++;
            } else {
                if (v > k) {
                    ok = false;
                    break;
                } else {
                    sol.push_back(v);
                }
            }
        }

        if (ok) {
            for (int x : sol) {
                cout << x << ' ';
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }
}