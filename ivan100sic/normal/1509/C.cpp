// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
ll a[2005];
ll d[2005][2005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    for (int l=n-2; l>=0; l--) {
        for (int r=l+1; r<n; r++) {
            d[l][r] = min(d[l+1][r], d[l][r-1]) + a[r] - a[l];
        }
    }

    cout << d[0][n-1] << '\n';

}