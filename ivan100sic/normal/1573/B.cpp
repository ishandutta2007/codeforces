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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        vector<int> bm(n);
        partial_sum(b.begin(), b.end(), bm.begin(), [](int x, int y) {
            return max(x, y);
        });

        int sol = n;
        for (int i=0; i<n; i++) {
            int it = lower_bound(bm.begin(), bm.end(), a[i]) - bm.begin();
            sol = min(sol, it + i);
        }

        cout << sol << '\n';
    }
}