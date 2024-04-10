// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll n, k, x;
ll a[200005], b[200005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> k >> x;
    for (ll i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);
    for (int i=1; i<n; i++) {
        b[i-1] = max(0ll, (a[i] - a[i-1] - 1) / x);
    }

    sort(b, b+n-1);
    for (int i=0; i<n-1; i++) {
        ll d = min(k, b[i]);
        b[i] -= d;
        k -= d;
    }

    cout << n - count(b, b+n-1, 0) << '\n';
}