// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

void ans(bool a) {
    cout << (a ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;

        if (n == 1) {
            ans(m == 0 && k >= 2);
            continue;
        }

        ll lim = n*(n-1) / 2;

        if (m < n - 1 || m > lim) {
            ans(false);
        } else if (m == lim) {
            ans(k >= 3);
        } else {
            ans(k >= 4);
        }
    }
}