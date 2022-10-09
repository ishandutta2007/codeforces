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

        if (accumulate(begin(a), end(a), 0) != accumulate(begin(b), end(b), 0)) {
            cout << "-1\n";
            continue;
        }

        vector<pair<int, int>> sol;
        while (1) {
            int f = 0;
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (a[i] > b[i] && a[j] < b[j]) {
                        sol.emplace_back(i+1, j+1);
                        f = 1;
                        a[i]--;
                        a[j]++;
                    }
                }
            }
            if (!f) break;
        }

        cout << sol.size() << '\n';
        for (auto [x, y] : sol) {
            cout << x << ' ' << y << '\n';
        }
    }
}