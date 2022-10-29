#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        ll k, n;
        cin >> n >> k;
        ll ans = (min(k, n - 1) + 1) * min(k, n - 1) / 2;
        if (k - n + 1 > 0) ans++;
        cout << ans << endl;
    }
}