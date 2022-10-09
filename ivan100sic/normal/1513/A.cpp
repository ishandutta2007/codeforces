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
        int n, k;
        cin >> n >> k;
        if (k > (n-1) / 2) {
            cout << "-1\n";
        } else {
            vector<int> a(n);
            for (int i=0; i<k; i++) {
                a[2*i + 1] = n-i;
            }
            for (int i=0, j=0; i<n; i++) {
                if (a[i] == 0) {
                    a[i] = ++j;
                }
            }

            for (int x : a) cout << x << ' ';
            cout << '\n';
        }
    }
}