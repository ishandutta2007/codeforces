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
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        if (a[0] == 1) {
            cout << n+1;
            for (int i=1; i<=n; i++) {
                cout << ' ' << i;
            }
            cout << '\n';
        } else {
            int j = find(begin(a), end(a), 1) - begin(a);
            if (j == n) {
                for (int i=1; i<=n+1; i++) {
                    cout << i << " \n"[i == n+1];
                }
            } else {
                for (int i=1; i<=j; i++) {
                    cout << i << ' ';
                }
                cout << n+1;
                for (int i=j+1; i<=n; i++) {
                    cout << ' ' << i;
                }
                cout << '\n';
            }
        }
    }
}