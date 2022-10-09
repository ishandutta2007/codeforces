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
        vector<int> a(n), b(n), az(3*n+5), bz(n+1);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];
        sort(begin(a), end(a));
        sort(begin(b), end(b), greater<int>());

        for (int i=0; i<n; i++) {
            az[i+1] = az[i] + a[i];
            bz[i+1] = bz[i] + b[i];
        }

        for (int x=n; x<=3*n; x++) {
            // test
            int r = x - x / 4;
            int sa = az[x] - az[x-r];
            int sb = bz[min(r, n)];

            if (sa >= sb) {
                cout << x-n << '\n';
                break;
            }

            // incr
            az[x+1] = az[x] + 100;
        }
    }
};