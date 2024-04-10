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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<int> id;
        for (int i=0; i<n; i++) {
            if (i >= x || n-1-i >= x) {
                id.push_back(i);
            }
        }

        vector<int> b;
        for (int x : id) {
            b.push_back(a[x]);
        }

        sort(begin(b), end(b));
        for (int i=0; i<(int)b.size(); i++) {
            a[id[i]] = b[i];
        }

        if (is_sorted(begin(a), end(a))) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}