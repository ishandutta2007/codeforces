// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

void ans(bool x) {
    cout << (x ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k, c = 0;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for (int& x : a) cin >> x;
        b = a;
        sort(begin(b), end(b));
        for (int i=1; i<n; i++) {
            int j = lower_bound(begin(b), end(b), a[i-1]) - begin(b);
            int k = lower_bound(begin(b), end(b), a[i]) - begin(b);
            if (j + 1 != k) {
                c++;
            }
        }

        ans(c + 1 <= k);
    }
}